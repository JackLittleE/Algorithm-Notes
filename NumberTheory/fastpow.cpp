#include "NumberTheory.h"


/*
* n Ϊ����ʱ, a^{n} = a^{n / 2} * a^{n / 2} * a
* n Ϊż��ʱ, a^{n} = a^{n / 2} * a^{n / 2}
*/
int NumberTheory::fastpow(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n % 2 == 1)
			ans *= a;
		a *= a;
		n /= 2;
	}
	return ans;
}