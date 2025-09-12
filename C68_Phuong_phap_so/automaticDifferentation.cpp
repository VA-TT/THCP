#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <numbers>

class Dual
{
private:
    double m_val{1.0};
    double m_der{1.0};

public:
    Dual(double val, double der)
        : m_val{val}, m_der{der} {}
    Dual(double val)
        : m_val{val}, m_der{1} {}
    Dual() = default;
    Dual(const Dual &) = default;
    Dual(Dual &&) = default;
    Dual &operator=(const Dual &) = default;
    Dual &operator=(Dual &&) = default;
    ~Dual() = default;

    constexpr double getVal() const { return m_val; }
    constexpr double getDer() const { return m_der; }
    void setVal(double val) { m_val = val; }
    void setDer(double der) { m_der = der; }
    friend Dual operator*(double k, const Dual &d)
    {
        Dual result{d};
        result.m_val *= k;
        result.m_der *= k;
        return result;
    }
    friend Dual operator*(const Dual &d, double k) { return k * d; }
    friend Dual operator+(const Dual &d, double a)
    {
        Dual result{d};
        result.m_val += a;
        return result;
    }
    friend Dual operator+(double a, const Dual &d)
    {
        return d + a;
    }
    friend Dual operator+(const Dual &d1, const Dual &d2)
    {
        Dual result{d1};
        result.m_val += d2.m_val;
        result.m_der += d2.m_der;
        return result;
    }
    friend Dual operator-(const Dual &d1, const Dual &d2)
    {
        return d1 + (-1) * d2;
    }
    friend Dual operator*(const Dual &d1, const Dual &d2)
    {
        Dual result{};
        result.m_val = d1.m_val * d2.m_val;
        result.m_der = d1.m_val * d2.m_der + d1.m_der * d2.m_val;
        return result;
    }
    friend Dual operator/(const Dual &d1, const Dual &d2)
    {
        Dual result{};
        result.m_val = d1.m_val / d2.m_val;
        result.m_der = (d1.m_der * d2.m_val - d1.m_val * d2.m_der) / (d2.m_val * d2.m_val);
        return result;
    }

    friend std::ostream &operator<<(std::ostream &out, const Dual &d)
    {
        out << d.m_val << " + " << d.m_der << "E \n";
        return out;
    }
};

template <typename T>
T myFunc(T x)
{
    return sin(x * x);
}

Dual sin(const Dual &d)
{
    return Dual{std::sin(d.getVal()), std::cos(d.getVal()) * d.getDer()};
}
Dual cos(const Dual &d)
{
    return Dual{std::cos(d.getVal()), -std::sin(d.getVal()) * d.getDer()};
}

template <typename T>
double automaticDiff(T x0)
{
    Dual d{x0};
    Dual result{myFunc(d)};
    return result.getDer();
}
int main()
{
    double x0{std::numbers::pi * 0.5};
    std::cout << "f(x0) = " << myFunc(x0) << '\n';
    std::cout << "f'(x0) = " << automaticDiff(x0) << '\n';
    return 0;
}