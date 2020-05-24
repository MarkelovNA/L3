#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

int main()
{
    const auto input = read_input(cin, true);

    const auto bins=make_histogram(input);

    double bin_height; //For module tests
    show_histogram_svg(bins, bin_height);

    return 0;
}
