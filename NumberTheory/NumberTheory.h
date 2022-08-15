#pragma once
#include <tuple>


// 数论类算法
namespace NumberTheory
{
	/*-------------------- fastpow.cpp --------------------*/


	/*
	* @fn - fastpow
	* 计算 a^{n}
	*
	* @para a - 底数
	* @para n - 指数
	*
	* @retn a^{n}
	*/
	int fastpow(int a, int n);


	/*-------------------- gcd.cpp --------------------*/


	/*
	* @fn - gcd
	* 求两个数的最大公因数(greatest common divisor，gcd)
	*
	* @para a, b - 代求数字
	*
	* @retn - a 和 b 的最大公约数
	*/
	int gcd(int a, int b);


	/*
	* @fn - exgcd
	* 求解方程 a * x + b * y = gcd(a, b)
	*
	* @para a, b - 方程中的系数
	*
	* @retn - (x, y, gcd(a, b)) -> 方程的解, a 和 b 的最大公约数
	*/
	std::tuple<int, int, int> exgcd(int a, int b);


	/*
	* @fn - exgcd
	* 求解方程 a * x + b * y = k
	*
	* @para a, b, k - 方程中的系数
	*
	* @retn - (bool, x, y) -> 方程有无解, 方程的解
	*/
	std::tuple<bool, int, int> exgcd(int a, int b, int k);


	/*-------------------- inv.cpp --------------------*/


	/*
	* @fn - inv
	* 求乘法逆元, 即 a * inv(a) = 1 (mod m)
	*
	* @para a - 待求的数
	*
	* @para m - 模数
	*
	* @retn - a 的乘法逆元, 返回为 0 说明逆元不存在(a 与 m 不互质)
	*/
	int inv(int a, int m);


}