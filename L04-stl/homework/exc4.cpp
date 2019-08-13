#include <list>
#include <vector>
#include <iostream>


int main()
{

/*  std::list<int> l;
    for(int i = 1; i<=1000000; i++)
    {
        l.emplace_back(i);
    }

    Time of execution for list:
    real    0m0,168s
    user    0m0,167s
    sys     0m0,000s

    auto it = std::next(l.begin(),499999);
    std::cout << "Value of item with index 500000: " << *it << '\n';


    Time of execution for list with printing:
    real    0m0,173s
    user    0m0,138s
    sys     0m0,028s 
*/

    std::vector<int> v;
    for(int i = 1; i<=1000000; i++)
    {
        v.emplace_back(i);
    } 

    auto it = std::next(v.begin(),499999);
    std::cout << "Value of item with index 500000: " << *it << '\n';

/*
    Time of execution for vector with printing:
    real    0m0,026s
    user    0m0,022s
    sys     0m0,004s 
*/
}
