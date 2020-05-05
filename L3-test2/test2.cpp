#include "C:\Users\markn\OneDrive\Desktop\Lab3\svg.h"

#include <cassert>

void scalling_same()
{

    double height_1;
    show_histogram_svg({1,1,1},height_1);
    double height_2;
    show_histogram_svg({322,322,322}, height_2);

    assert(height_1==height_2);

}

void scalling_correct()
{

    double height_1;
    show_histogram_svg({1, 2, 3}, height_1);

    double height_2;
    show_histogram_svg({3, 2, 1}, height_2);

    assert(height_1>height_2);

}

int main()
{
    scalling_same();
    scalling_correct();
}
