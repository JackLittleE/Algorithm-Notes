#include "NumberTheory.h"


/*
* �ⷽ�� ax - my = 1, x ��Ϊ inv(a)
*/
int NumberTheory::inv(int a, int m)
{
	auto [x, y, g] = NumberTheory::exgcd(a, m);
	if (g != 1) 
		return 0;
	return (x % m + m) % m;
}