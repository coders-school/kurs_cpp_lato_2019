#include <forward_list>
#include <iostream>


int main()
{
    std::forward_list<int> fl {1,3,4,5,6,8,9};
    auto it1 = fl.begin();
    auto it2 = fl.end();

    std::cout << "Forward list size: " << std::distance(it1, it2) << '\n';

    auto it3 = std::next(it1,4);
    std::cout << "Value for 5th element: " << *it3 << '\n';  

    std::cout << "Distance from beginnig to 5th element: " << std::distance(it1, it3) << '\n';     

    return 0;
}