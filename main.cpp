#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

using namespace std;

int main()
{
    curl_global_init(CURL_GLOBAL_ALL);

    const auto input = read_input(cin, true);
    const auto bins=make_histogram(input);
    double bin_height; //For module tests
    show_histogram_svg(bins, bin_height);

    return 0;
}
