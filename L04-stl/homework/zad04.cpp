// #include <list>
#include <vector>
#include <iostream>


// void fillListWithAscendingIntegers(std::list<int> &list, int count){
//     for(int i=1; i<=count; ++i) list.emplace_back(i);
// }

void vectorEmplaceBackAscendingIntegers(std::vector<int> &vector, int count){
    for(int i=1; i<=count; ++i) vector.emplace_back(i);
}

// int returnListElement(const std::list<int> &l, int n){
//     auto it = l.begin();
//     for(int i=0; i<n-1; ++i) ++it;
//     return *it;
//}

int main()
{
    // std::list<int> list1 = {}; 
    // fillListWithAscendingIntegers(list1, 1000000);
        // time ./zad04.out 
        // real    0m0,094s
        // user    0m0,065s
        // sys     0m0,028s
    // std::cout << returnListElement(list1, 500000) << '\n';   
        // time ./zad04.out 
        // real    0m0,094s
        // user    0m0,065s
        // sys     0m0,028s
    std::vector<int> vector1 = {};
    vectorEmplaceBackAscendingIntegers(vector1, 1000000);
    std::cout << vector1.at(499999);
        // time ./zad04.out 
        // 500000
        // real    0m0,020s
        // user    0m0,005s
        // sys     0m0,016s
    return 0;
}
