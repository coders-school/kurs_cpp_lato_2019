#include <random>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>

int main()
{

    std::vector<char> v1(127);
    std::iota(v1.begin(), v1.end(), 'a');
    v1.emplace_back(' ');
    std::vector<char> v2 = v1;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v2.begin(), v2.end(), g);

    std::map<char, char> m{};
    for (auto i = 0; i < v1.size(); i++)
    {
        m.emplace(std::make_pair(v1[i], v2[i]));
    }

    std::map<char, char> m2{};

    for (auto i = 0; i < v1.size(); i++)
    {
        m2.emplace(std::make_pair(v2[i], v1[i]));
    }

    std::string text;
    std::string text2;
    std::cout << "podaj tekst, ktory chcesz szyfrowac:" << std::endl;
    std::getline(std::cin, text);
  
    for (auto &it : text)
    {
        it = m[it];
    }

    std::cout << "Twoj zaszyfrowany tekst to: " << text << std::endl;

    for (auto &it : text)
    {
        it = m2[it];
    }

    std::cout << "Twoj odszyfrowany tekst to: " << text << std::endl;
    return 0;
}
