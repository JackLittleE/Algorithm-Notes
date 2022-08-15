#pragma once
#include <vector>
#include <complex>


// 信号处理类算法
namespace Signal
{

	/*-------------------- transform.cpp --------------------*/


	/*
	* @fn - dft
	* 计算输入序列的离散傅里叶变换(Discrete Fourier Transform, DFT)
	* 
	* @para x - 输入序列
	* 
	* @retn - 输入序列 x 的 DFT 变换结果
	*/
	std::vector<std::complex<double>> dft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - idft
	* 计算输入序列的离散傅里叶逆变换(Inverse Discrete Fourier Transform, IDFT)
	* 
	* @para x - 输入序列
	* 
	* @retn - 输入序列 x 的 IDFT 变换结果
	*/
	std::vector<std::complex<double>> idft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - fft
	* 计算输入序列的快速傅里叶变换(Fast Fourier Transform, FFT)
	*
	* @para x - 输入序列
	*
	* @retn - 输入序列 x 的 FFT 变换结果
	*
	* @note : 输入序列 x 的长度必须为 2 的整数次幂
	*/
	std::vector<std::complex<double>> fft(const std::vector<double>& x);


	/*
	* @fn - fft
	* 计算输入序列的快速傅里叶变换(Fast Fourier Transform, FFT)
	*
	* @para x - 输入序列
	*
	* @retn - 输入序列 x 的 FFT 变换结果
	* 
	* @note : 输入序列 x 的长度必须为 2 的整数次幂
	*/
	std::vector<std::complex<double>> fft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - ifft
	* 计算输入序列的快速傅里叶逆变换(Inverse Fast Fourier Transform, IFFT)
	*
	* @para x - 输入序列
	*
	* @retn - 输入序列 x 的 IFFT 变换结果
	*
	* @note : 输入序列 x 的长度必须为 2 的整数次幂
	*/
	std::vector<std::complex<double>> ifft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - Hilbert
	* 计算输入序列的希尔伯特(hilbert)变换
	*
	* @para x - 输入序列
	*
	* @retn - 输入序列 x 的希尔伯特变换结果(实信号对应的虚信号)
	*
	* @note : 输入序列 x 的长度必须为 2 的整数次幂
	*/
	std::vector<double> hilbert(const std::vector<double>& x);


	/*
	* @fn - Hilbert
	* 使用 fft 计算输入序列的希尔伯特(hilbert)变换
	*
	* @para fft - 输入序列(x)的 fft 变换
	*
	* @retn - 输入序列 x 的希尔伯特变换结果(实信号对应的虚信号)
	*
	* @note : 输入序列 x 的长度必须为 2 的整数次幂
	*/
	std::vector<double> hilbert_fft(const std::vector<std::complex<double>>& fft);

}