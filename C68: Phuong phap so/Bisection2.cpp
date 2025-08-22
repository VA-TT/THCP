#include <iostream>
#include <cmath>
#include <iomanip>
#include <functional>
#include <limits>

// Example function
double myfunc(double x)
{
    return 8.0 * x * x * x - 4.0 * x * x - 3.0 * x + 1.0;
}

// Robust iterative bisection
// Returns true on success and stores root in 'root'.
bool bisection(const std::function<double(double)> &f,
               double a, double b, double eps,
               double &root, int max_iter = 1000)
{
    if (a > b)
        std::swap(a, b);

    double fa = f(a);
    double fb = f(b);

    // Quick checks
    if (std::abs(fa) <= eps)
    {
        root = a;
        return true;
    }
    if (std::abs(fb) <= eps)
    {
        root = b;
        return true;
    }

    if (fa * fb > 0.0)
    {
        // same sign -> cannot guarantee a root
        return false;
    }

    for (int i = 0; i < max_iter && (b - a) / 2.0 > eps; ++i)
    {
        double mid = 0.5 * (a + b);
        double fm = f(mid);

        if (std::abs(fm) <= eps)
        {
            root = mid;
            return true;
        }

        if (fa * fm < 0.0)
        {
            b = mid;
            fb = fm;
        }
        else
        {
            a = mid;
            fa = fm;
        }
    }

    root = 0.5 * (a + b);
    return true;
}

int main()
{
    double eps = 1e-12;
    double root = std::numeric_limits<double>::quiet_NaN();

    bool ok = bisection(myfunc, 0.7, 0.8, eps, root, 1000);

    std::cout << std::fixed << std::setprecision(15);
    if (ok)
    {
        std::cout << "Root found: " << root << std::endl;
        std::cout << "f(root) = " << std::scientific << std::setprecision(3) << myfunc(root) << std::endl;
    }
    else
    {
        std::cout << "Bisection failed: f(a) and f(b) have same sign or invalid interval." << std::endl;
    }

    return ok ? 0 : 1;
}
