#include <iostream>
#include <list>
#include <vector>


void pt1();

int main() {
    std::vector<int> testlist{};
    testlist.reserve(1'000'000);
    for(int i=0; i<1'000'000; i++)
    {
        testlist.push_back(i+1);
    }

//  For list
//    real    0m0,122s
//    user    0m0,114s
//    sys     0m0,008s

//  For Vector
//    real    0m0,044s
//    user    0m0,040s
//    sys     0m0,004s

    auto iterator = testlist.begin();
    std::advance(iterator, 499'999);
    std::cout << "Element 500000 : " << *iterator << std::endl;

//  For List
//    real    0m0,128s
//    user    0m0,120s
//    sys     0m0,008s

//  For Vector
//    real    0m0,046s
//    user    0m0,047s
//    sys     0m0,000s

    return 0;
}

