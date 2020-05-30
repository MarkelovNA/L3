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
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_major = 0x0000ff;

    if ((info & 0x80000000) == 0)
    {
        DWORD version_major = version & mask_major;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        printf("Windows v%u.%u (build %u)", version_major, version_minor, build);
    }
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
