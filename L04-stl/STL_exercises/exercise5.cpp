#include <map>
#include <iostream>
#include <string>

void printContent(std::map<int, std::string> a)
{
    for(auto elements: a)
    {
        std::cout << "{" << elements.first << ", " << elements.second << "}" << std::endl;
    }
}

void printNumberOfValuesPerKey(std::map<int, std::string> a)
{
    for(auto elements : a) //for(auto it = a.begin(); it != a.end(); it++)
    {
        std::cout << a.count(elements.first) << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::map <int,std::string> m =
    {
        {1, "one"},
        {2, "two"},
        {3, "thr"},
        {4, "four"},
        {5, "five"},
    };
    m.insert(std::make_pair(3, "three")); // or m[3] = "three";
    m.erase(5);
    printNumberOfValuesPerKey(m);
    auto it = m.find(4);
    std::cout << it->first << " " << it->second << std::endl;
}