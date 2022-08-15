#include "NumberTheory.h"


/*
* 使用辗转相除法, gcd(a, b) = gcd(b, a % b)
*/
int NumberTheory::gcd(int a, int b)
{
    return b > 0 ? NumberTheory::gcd(b, a % b) : a;
}


/*
* * ax + by = gcd(a, b) -> ax + by = gcd(b, a % b) -> bt * x + (a % b)ty = gcd(b, a % b)
* a % b = a - a / b * b (/ 为整除)
* ax + by = aty + b(tx - a / b * ty) -> x = ty, y = tx - a / b * ty
*/
std::tuple<int, int, int> NumberTheory::exgcd(int a, int b)
{
    if (b == 0)
        return {1, 0, a};
    auto [y, x, g] = NumberTheory::exgcd(b, a % b);
    y = y - a / b * x;
    return {x, y, g};
}


/*
* 当 k % d == 0 时, 方程才有解
* 解为 ax + by = gcd(a, b) 的 k / gcd(a, b) 倍 (/ 为整除)
*/
std::tuple<bool, int, int> NumberTheory::exgcd(int a, int b, int k)
{
    auto [x, y, g] = NumberTheory::exgcd(a, b);
    if (k % g != 0) 
        return { false, 0, 0 };
    return { true, x * k / g, y * k / g };
}