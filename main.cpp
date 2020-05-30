#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <cstdio>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
    Input input;
    Configurations config=input_config(argc, argv);

    //Hint for user
    if (config.UseHint)
    {
        cerr << "\n###########################################################"<<
        "\nHELP:\n *For making input from web enter URL of page to parameters"<<
        "\n *For using CURLOPT_VERBOSE mode enter ''-verbose''" << "\n"
        << "###########################################################\n";
        exit(2);
    }

    //input data
    if (config.UrlPage)
    {
        input=download(config.UrlPage, config.UseVerbose);
    }
    else
    {
        input=read_input(cin, true);
    }

    //making histogram
    const auto bins=make_histogram(input);
    double bin_height; //For module tests
    show_histogram_svg(bins, bin_height);

    return 0;
}
