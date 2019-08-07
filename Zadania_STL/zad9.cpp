#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool palindromMismatch (const std::string &napis)
{
    auto iterators = std::mismatch(napis.begin(), napis.end(), napis.rbegin(), napis.rend());
    return (iterators.first == napis.end() && iterators.second == napis.rend());
}

int main(){
    std::string napis;
    std::cout<<"Podaj napis do sprawdzenia: ";
    getline(std::cin,napis);
    std::cout<<std::boolalpha<<palindromMismatch(napis)<<std::endl;
    return 0;
}
