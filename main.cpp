#include <iostream>
#include "NumberTheory/NumberTheory.h"
#include "Signal/Signal.h"
using namespace std;

int main()
{
    vector<double> x = { 1, 2, 3, 4, 5, 6, 7, 8 };
    for (const auto& i : Signal::ifft(Signal::fft(x)))
        cout << i << endl;
    return 0;
}