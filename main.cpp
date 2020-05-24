#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

struct Input
{
    vector <double> numbers;
    size_t bin_count;
};

Input read_input(istream& in)
{
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter column count: ";
    in >> data.bin_count;

    return data;
}

int main()
{
    const auto input = read_input(cin);

    const auto bins=make_histogram(input.numbers,input.bin_count);

    double bin_height;
    show_histogram_svg(bins, bin_height);

    return 0;
}
