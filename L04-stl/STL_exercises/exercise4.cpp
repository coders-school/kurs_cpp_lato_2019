#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

void printCapacity(std::vector<int> a)
{
    std::cout<< a.size()<<std::endl;
    std::cout<< a.capacity() << std::endl;
}

int main()
{
    std::vector<int> v(1000000);
    std::iota(v.begin(), v.end(), 1);
    printCapacity(v);
    std::cout << "Displaying 500000th element of vector v: " << v[499999] << std::endl;
    return 0;
}