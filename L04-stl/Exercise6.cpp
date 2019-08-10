#include <iostream>
#include <forward_list>
#include <ctime>
#include <iterator>
#include <vector>
#include <numeric>
#include <string>

int main()
{
    std::forward_list<std::string> fList
    {
        "allahakbar",
        "kajak",
        "piwo",
        "ceplusplus",
        "facebook",
        "krasnal",
        "zegarek",
        "okulary",
        "1234567889"
    };
    std::forward_list<std::string>::iterator itB = std::begin(fList);
    std::forward_list<std::string>::iterator itE = std::end(fList);
    int i=0;
    for(auto element : fList)
    {
        ++i;
    }
    std::cout << i << std::endl;
    std::advance(itB,4);
    std::cout << *itB << std::endl;
    std::cout<<std::distance(std::begin(fList),itB)<<std::endl;
    }