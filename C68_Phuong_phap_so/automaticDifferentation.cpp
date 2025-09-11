#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

struct Dual
{
    double val{1.0};
    double der{1.0};
};

double myFunc(double x)
{
    return x * x;
}

double automaticDiff(std::function<double(double)> f, double x0)
{
}
int main()
{

    return 0;
}