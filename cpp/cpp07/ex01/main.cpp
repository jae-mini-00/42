#include <iostream>
#include <iomanip>
#include "iter.hpp"

template <typename T>
void print(const T& data)
{
    std::cout   << data << std::endl;
}

// void print(const char& c)
// {
//     std::cout   << c << std::endl;
// }

// void print(const int& num)
// {
//     std::cout   << num << std::endl;
// }

// void print(const long& num)
// {
//     std::cout   << num << std::endl;
// }

// void print(const float& num)
// {
//     std::cout   << num << 'f' << std::endl;
// }

// void print(const double& num)
// {
//     std::cout   << num << std::endl;
// }

int main(void)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout  << "=====char test=====" << std::endl;
    char c_arr[3] = {'a', 'b', 'c'};
    iter(c_arr, 3, print);
    std::cout   << std::endl;

    std::cout  << "=====int test=====" << std::endl;
    int i_arr[3] = {0, 1, 2};
    iter(i_arr, 3, print);
    std::cout   << std::endl;

    std::cout  << "=====long test=====" << std::endl;
    long l_arr[3] = {0, 1, 2};
    iter(l_arr, 3, print);
    std::cout   << std::endl;

    std::cout  << "=====float test=====" << std::endl;
    float f_arr[3] = {0, 1, 2};
    iter(f_arr, 3, print);
    std::cout   << std::endl;

    std::cout  << "=====double test=====" << std::endl;
    double d_arr[3] = {0, 1, 2};
    iter(d_arr, 3, print);
    std::cout   << std::endl;
    return 0;
}