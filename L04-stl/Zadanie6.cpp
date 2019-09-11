#include <iostream>
#include <forward_list>
#include <iterator>

int main()
{
    std::forward_list<int> fwList{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    auto itStart = begin(fwList);
    auto itStop = end(fwList);

    std::cout << "size: " << std::distance(itStart, itStop) << std::endl;

    auto itUpTo5 = fwList.begin();

    std::advance(itUpTo5, 4);

    std::cout << "Element number 5: " << *itUpTo5 << std::endl;

    std:: cout << "Distance: " << std::distance(itStart, itUpTo5) << std::endl;
}