#include <iostream>
#include <cmath>
#include <iomanip>

double myfunc(double x)
{
    return std::pow(x, 3) - 2;
}

double bisection(double a, double b, double epsilon)
{
    double fa{myfunc(a)};
    double fb{myfunc(b)};

    // Kiểm tra điều kiện dừng
    if (std::abs(a - b) < epsilon)
    {
        return (a + b) / 2.0;
    }

    // Kiểm tra xem có root trong khoảng [a,b] không
    if (fa * fb >= 0)
    {
        std::cerr << "Error: No root in interval [" << a << ", " << b << "]" << std::endl;
        return NAN;
    }

    double x0 = 0.5 * (a + b);
    double fx0 = myfunc(x0);

    // Chọn khoảng con chứa root
    if (fa * fx0 < 0)
    {
        return bisection(a, x0, epsilon);
    }
    else
    {
        return bisection(x0, b, epsilon);
    }
}

int main()
{
    // Error eps = 1e-12
    double epsilon{1e-10};
    // Sửa khoảng để chứa root: x³ - 2 = 0 => x = ∛2 ≈ 1.26
    double x0 = bisection(1, 2, epsilon);

    // In với độ chính xác cao
    std::cout
        << std::fixed << std::setprecision(15);
    std::cout << "Result: x0 = " << x0 << std::endl;

    return 0;
}