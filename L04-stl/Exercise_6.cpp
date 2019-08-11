#include <forward_list>
#include <iostream>
#include <iterator>

int main()
{
        std::forward_list<int> f {10,20,30,40,50,60,70};

        auto begin = std::begin(f);
        auto end = std::end(f);

        std::cout << "list size: "  << std::distance(begin, end) << "\n";

        auto fifth = std::begin(f);
        std::advance(fifth, 4);

        std::cout << "5th: " << *fifth << "\n";

        std::cout << "distance: " << std::distance(begin, fifth) << "\n";
}

