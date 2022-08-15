#pragma once
#include <tuple>


// �������㷨
namespace NumberTheory
{
	/*-------------------- fastpow.cpp --------------------*/


	/*
	* @fn - fastpow
	* ���� a^{n}
	*
	* @para a - ����
	* @para n - ָ��
	*
	* @retn a^{n}
	*/
	int fastpow(int a, int n);


	/*-------------------- gcd.cpp --------------------*/


	/*
	* @fn - gcd
	* �����������������(greatest common divisor��gcd)
	*
	* @para a, b - ��������
	*
	* @retn - a �� b �����Լ��
	*/
	int gcd(int a, int b);


	/*
	* @fn - exgcd
	* ��ⷽ�� a * x + b * y = gcd(a, b)
	*
	* @para a, b - �����е�ϵ��
	*
	* @retn - (x, y, gcd(a, b)) -> ���̵Ľ�, a �� b �����Լ��
	*/
	std::tuple<int, int, int> exgcd(int a, int b);


	/*
	* @fn - exgcd
	* ��ⷽ�� a * x + b * y = k
	*
	* @para a, b, k - �����е�ϵ��
	*
	* @retn - (bool, x, y) -> �������޽�, ���̵Ľ�
	*/
	std::tuple<bool, int, int> exgcd(int a, int b, int k);


	/*-------------------- inv.cpp --------------------*/


	/*
	* @fn - inv
	* ��˷���Ԫ, �� a * inv(a) = 1 (mod m)
	*
	* @para a - �������
	*
	* @para m - ģ��
	*
	* @retn - a �ĳ˷���Ԫ, ����Ϊ 0 ˵����Ԫ������(a �� m ������)
	*/
	int inv(int a, int m);


}