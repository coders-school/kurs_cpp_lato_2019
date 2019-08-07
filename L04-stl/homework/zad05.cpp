#include <iostream>
#include <map>

void printMapContent(const std::map<int, std::string> &map){
    for(const auto & [integer_, string_] : map)
        std::cout <<  integer_ << ": " << string_ << '\n';
}

int main()
{
    std::map<int, std::string> map1 = {
        {1, "one"},
        {2, "two"},
        {3, "thr"},
        {4, "four"},
        {5, "five"},
    };

    map1[3] = "three";
    auto it = map1.find(5);
    map1.erase(it);
    printMapContent(map1);
    it = map1.find(4);
    std::cout << "key: " << it->first << ", " << "value: " << it->second << '\n';
    return 0;
}
