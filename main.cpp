#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <cstdio>
#include <windows.h>

using namespace std;

int main()
{
    DWORD info = GetVersion();
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;
    printf("Windows version is %u.\n", version);
    return 0;

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    const auto bins=make_histogram(numbers, bin_count);

    double bin_height;
    show_histogram_svg(bins, bin_height);

    return 0;
}
