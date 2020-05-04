#pragma once

#include <iostream>
#include <vector>
using namespace std;

vector<double> input_numbers(size_t count);
void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(vector<double>numbers, size_t bin_count);
void show_histogram_text(vector<size_t> bins);
