#include <iostream>
#include <array>

void printArray(const std::array<int, 10> &a){
    for(const auto & element : a){
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

void printArray2(const std::array<int, 10> &a){
    for(auto it = a.begin(); it!=a.end(); ++it){
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 10> a1 = {};
    a1.fill(5);
    a1.at(3) = 3;
    std::array<int, 10> a2 = {};
    a1.swap(a2);
 
    printArray(a1);
    printArray2(a2);
    
    // int* p1 = a1.data();    // do czego to się może przydać?
    // int* p2 = a2.data();
    return 0;
}