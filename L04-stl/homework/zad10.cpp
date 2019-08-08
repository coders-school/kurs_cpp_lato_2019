#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void printVectorWithCopy(const std::vector<std::string>& v)
{
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<std::string>(std::cout, " | "));
    std::cout << "\n";
}

int main()
{
    std::vector<std::string> v0 
        {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "three", "four", "five"};
    std::vector<std::string> v1(v0.begin(), v0.end());
    printVectorWithCopy(v1);
    std::sort(v1.begin(), v1.end());
    printVectorWithCopy(v1);
    auto itu = std::unique(v1.begin(), v1.end());
    v1.erase(itu, v1.end());
    printVectorWithCopy(v1);
    std::reverse(v1.begin(), v1.end());
    printVectorWithCopy(v1);    
    return 0;
}