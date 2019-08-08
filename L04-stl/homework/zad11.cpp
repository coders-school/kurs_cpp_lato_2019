#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>

void printDeque(const std::deque<int> &d)
{
    for(const auto & elements : d)
        std::cout << elements << ' ';
    std::cout << '\n';
}

void alternatePrintDeque(const std::deque<int> &d)
{
    std::transform( d.cbegin(), 
                    d.cend(), 
                    std::ostream_iterator<int>(std::cout, " "),
                    [](const auto & element){ return element; });
    std::cout << '\n';
}

int main()
{
    std::deque<int> deq1 = {};
    srand(static_cast<int>(time(NULL)));
    std::generate_n(std::back_inserter(deq1), 14, [](){ return rand()%7+1; });
    printDeque(deq1);
    alternatePrintDeque(deq1);
    std::sort(deq1.begin(), deq1.end());
    printDeque(deq1);
    // auto it = std::unique(deq1.begin(), deq1.end());
    // deq1.erase(it, deq1.end());
    deq1.erase(std::unique(deq1.begin(), deq1.end()), deq1.end());
    printDeque(deq1);
    std::rotate( deq1.begin(), 
                 deq1.begin()+(std::distance(deq1.begin(), deq1.end())/2),
                 deq1.end() );
    printDeque(deq1);
    return 0;
}