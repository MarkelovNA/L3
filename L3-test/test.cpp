#include "C:\Users\markn\OneDrive\Desktop\Lab3\histogram.h"

#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min;
    double max;
    find_minmax({-1, -5,-228}, min, max);
    assert(min == -228);
    assert(max == -1);
}

void test_one_number()
{
    double min;
    double max;
    find_minmax({666}, min, max);
    assert(min == 666);
    assert(max == 666);
}

void test_same_numbers()
{
    double min;
    double max;
    find_minmax({3,3,3}, min, max);
    assert(min == 3);
    assert(max == 3);
}

void test_empty_vector()
{
    double min;
    double max;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

int main()
{
    test_positive();
    test_negative();
    test_one_number();
    test_same_numbers();
    test_empty_vector();
}
