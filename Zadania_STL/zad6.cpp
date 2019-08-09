// Exercise 6:
// 1.Create std::forward_list with some data (integers) at least 7.
// 2. Get two iterators with global functions begin(), end().
// 3.Print size of the list
// 4. Get an iterator to the 5th element and print its value.
// 5.Print distance() from beginning to this iterator

#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    std::forward_list<int>::iterator itb = std::begin(l);
    std::forward_list<int>::iterator itEnd = std::end(l);
    int size = 0;

    for (auto itb : l)
        size ++;
    std::cout << "List size: " << size << std:: endl; 

    auto it = std::next(l.begin(),4);
    int distanceToFifth = distance(l.begin(), it);

    std::cout << "Distance from beginning to 5th element: " << distanceToFifth << std:: endl; 

    return 0;
}