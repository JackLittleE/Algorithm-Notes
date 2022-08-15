#include "signal.h"

#define PI 3.141592653589793


/*-------------------- dft --------------------*/


/*
* @fn - dft_core
* inverse == false - 计算 x 的 DFT
* inverse == true  - 计算 x 的 IDFT
*/
std::vector<std::complex<double>> dft_core(const std::vector<std::complex<double>>& x, bool inverse)
{
	const size_t N = x.size();
	std::vector<std::complex<double>> ans(N, 0); // 初始化长度为 N, 值为0
	for (size_t k = 0; k < N; k++) {
		for (size_t i = 0; i < N; i++) {
			ans[k] += x[i] * std::polar(1.0,
				(inverse ? 1 : -1) * 2 * PI * static_cast<double>(k) * static_cast<double>(i) / static_cast<double>(N));
			if (inverse)
				ans[k] /= static_cast<double>(N);
		}
	}
	return ans;
}


/*
* ans[k] = \sum_{i = 0}^{N - 1} x[i] * e^{-j\frac{2\pi}{N}ki}
*/
std::vector<std::complex<double>> Signal::dft(const std::vector<std::complex<double>>& x)
{
	return dft_core(x, false);
}


std::vector<std::complex<double>> Signal::idft(const std::vector<std::complex<double>>& x)
{
	return dft_core(x, true);
}


/*-------------------- fft --------------------*/


/*
* @fn - fft_core
* inverse == false - 计算 x 的 FFT
* inverse == true  - 计算 x 的 IFFT
* 对 x 是原地操作, 不需要返回值
*/
void fft_core(std::vector<std::complex<double>>& x, bool inverse)
{
	const size_t N = x.size();
	std::vector<std::complex<double>>& ans = x;

	// 求逆序数, 并替换
	for (size_t i = 1; i < N; i++) {
		size_t t = N | i;
		size_t tax = 0;

		while (t != 1) {
			tax <<= 1;
			tax |= t & 1;
			t >>= 1;
		}

		if (tax > i)
			std::swap(ans[tax], ans[i]);
	}

	for (size_t M = 1, len = 2; len <= N; M = len, len <<= 1) {
		auto Wn = std::polar(1.0, (inverse ? 1 : -1) * PI / static_cast<double>(M));
		for (size_t L = 0, R = len - 1; R <= N; L += len, R += len) {
			std::complex<double> w0 = 1;
			for (size_t p = L, lim = L + M; p < lim; p++) {
				auto t = w0 * ans[p + M];
				ans[p + M] = ans[p] - t;
				ans[p] = ans[p] + t;
				w0 *= Wn;
			}
		}
	}

	if (inverse) {
		for (size_t i = 0; i < N; i++)
			ans[i] /= static_cast<double>(N);
	}
}


std::vector<std::complex<double>> Signal::fft(const std::vector<double>& x)
{
	const size_t N = x.size();
	std::vector<std::complex<double>> ans(N, 0);
	for (size_t i = 0; i < N; i++)
		ans[i] = x[i];
	fft_core(ans, false);
	return ans;
}


/*
* 令 g[r] = x[2r], h[r] = x[2r + 1]
* 则 X[k] = G[k] + W_{n}^{k}H[k], X[k + \frac{N}{2}] = G[k] - W_{n}^{k}H[k]
*/
std::vector<std::complex<double>> Signal::fft(const std::vector<std::complex<double>>& x)
{
	std::vector<std::complex<double>> ans = x;
	fft_core(ans, false);
	return ans;
}


std::vector<std::complex<double>> Signal::ifft(const std::vector<std::complex<double>>& x)
{
	std::vector<std::complex<double>> ans = x;
	fft_core(ans, true);
	return ans;
}


/*-------------------- Hilbert --------------------*/


std::vector<double> Signal::hilbert(const std::vector<double>& x)
{
	return hilbert_fft(Signal::fft(x));
}

std::vector<double> Signal::hilbert_fft(const std::vector<std::complex<double>>& fft)
{
	std::vector<std::complex<double>> fft_temp = fft;

	const size_t N = fft_temp.size();
	for (size_t i = 0; i < N; i++) {
		if (i == 0) {
			continue;
		}
		else if (i < N / 2) {
			fft_temp[i] *= 2;
		}
		else {
			fft_temp[i] = 0;
		}
	}
	auto ifft_result = ifft(fft_temp);

	std::vector<double> ans(N);
	for (size_t i = 0; i < N; i++)
		ans[i] = ifft_result[i].imag();

	return ans;
}
