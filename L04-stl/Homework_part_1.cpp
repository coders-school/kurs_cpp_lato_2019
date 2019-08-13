#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <forward_list>
#include <functional>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <utility>

bool is_palindrome (std::string napis)
{
    std::string napis_temp = napis;
    std::reverse(std::begin(napis_temp),std::end(napis_temp));
    auto test = mismatch(napis.begin(),napis.end(),napis_temp.begin());
    return (test.first==napis.end());
}

int main () {

    std::cout<<"===========Exercise 4==========="<<std::endl;
    std::list <int> l{};
    l.resize(1000000);
    std::iota(l.begin(),l.end(),1);
    std::list<int>::iterator itr=l.begin();
    std::advance(itr,500000);
    std::cout<<*itr<<std::endl;
    //real 0,142s , user 0,138s, sys 0,004s
    std::vector<int> vec{};
    vec.resize(1000000);
    std::iota(vec.begin(),vec.end(),1);
    std::cout<<vec.at(500000)<<std::endl;
    //real 0,022s , user 0,013s, sys 0,009s

    std::cout<<"===========Exercise 6==========="<<std::endl;
    std::forward_list<int> numbers{1,2,3,4,16,6,7,15};
    std::forward_list<int>::iterator itr_l=std::begin(numbers);
    std::forward_list<int>::iterator itr_r=std::end(numbers);
    auto size{0};

    for (auto itr_l:numbers)
        ++size;
    std::cout<<size<<std::endl;
    std::advance(itr_l,4);
    std::cout<<*itr_l<<std::endl;
    std::cout<<std::distance(numbers.begin(),itr_l)<<std::endl;

    std::cout<<"===========Exercise 9========"<<std::endl;
    std::cout<<std::boolalpha<<is_palindrome("kajak")<<std::endl;
    std::cout<<std::boolalpha<<is_palindrome("wiktor")<<std::endl;

return 0;

}


