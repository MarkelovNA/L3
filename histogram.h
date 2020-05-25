#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <curl/curl.h>
using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

Input read_input(istream& in, bool prompt);
size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx);
Input download(const string& address);
vector<double> input_numbers(istream& in, size_t count);
void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(const Input input);
void show_histogram_text(vector<size_t> bins);
