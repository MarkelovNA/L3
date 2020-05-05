#include "svg.h"

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "' >"<< text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fil)
{
    cout << "<rect x='" << x <<"' y='" << y << "' width='" << width << "' height='" << height
         << "' stroke='" << stroke << "' fill='" << fil << "' />";
}

void show_histogram_svg(const vector<size_t>& bins, double& bin_height)
{

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_TOP = 20;
    const auto TEXT_HEIGHT = 30;
    const auto BIN_WIDTH = 30;
    const auto TEXT_BASELINE = 15;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double left =0;

    size_t max_count=bins[0];

    for (size_t bin : bins)
    {
        if (bin>max_count)
        {
            max_count=bin;
        }
    }

    for (size_t bin: bins)
    {
        const double bin_koeff = (double)(IMAGE_HEIGHT - TEXT_HEIGHT) / max_count;
        bin_height = bin * bin_koeff;

        svg_text(left + TEXT_BASELINE, TEXT_TOP, to_string(bin));
        svg_rect(left, TEXT_HEIGHT, BIN_WIDTH, bin_height, "red", "#ffeeee");
        left += BIN_WIDTH;
    }

    svg_end();
}
