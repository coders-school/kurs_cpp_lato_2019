#include <iostream>
#include <forward_list>
#include <ctime>
#include <iterator>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

bool isPalindrome(std::string v)
{
    auto iterators = std::mismatch(v.begin(), v.end(), v.rbegin(), v.rend());
    return (iterators.first==v.end() && iterators.second == v.rend());
    return 0;
        
}

int main()
{
    std::string v = "121";
    bool result = isPalindrome(v);
    std::cout << result << std::endl;

}