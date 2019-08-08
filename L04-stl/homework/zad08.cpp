#include <iostream>
#include <array>
#include <algorithm>

struct
{
    bool operator()(double& a, double& b) const
    {
        return std::abs(a) < std::abs(b);
    }
} AbsCompare;

void printArrayOfDoubles(std::array<double, 6> &arr)
{
    for(const auto & elements : arr)
    {
        std::cout << elements << ' ' << ' ';
    }
    std::cout << '\n';
}


int main()
{
    std::array<double, 6> arr1 = {5.0, 4.0, -1.4, 7.9, -8.22, 0.4};
    std::array<double, 6> arr2 = arr1;
    printArrayOfDoubles(arr1);
    printArrayOfDoubles(arr2);
    std::sort(arr1.begin(), arr1.end(), AbsCompare);
    std::sort(arr2.begin(), arr2.end(), [](const double a, const double b)
    {
        return std::abs(a) < std::abs(b);
    });
    printArrayOfDoubles(arr1);
    printArrayOfDoubles(arr2);
    return 0;
}