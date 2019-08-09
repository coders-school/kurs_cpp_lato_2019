#include <iterator>
#include <algorithm>
#include <iostream>
#include <forward_list>

static int i=0;

int main()
{

    std::forward_list<int> l{1,3,4,8,5,9,4,5};
    std::forward_list<int>::iterator it = l.begin();
     
    for(std::forward_list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " " << std::endl;
        i++;
    }
    std::cout << "Size of the list: " << i << std::endl;

    std::advance(it, 4);

    std::cout << "5th element: " << *it << std::endl;

    std::cout << "Distance: " << std::distance(l.begin(), it) << std::endl;
    return 0;
}
