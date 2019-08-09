#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
#include <random>

void printVector(const std::vector<char>& v)
{
    std::cout << ".";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<char>(std::cout, "."));
    std::cout << "\n";
}

void printMap(const std::map<char, char> &m)
{
    std::for_each(m.cbegin(), 
                  m.cend(), 
                  [](std::pair<char, char> p){ std::cout << "key: " << p.first << ",  value: " << p.second << "\n"; });
}

void insertAsciiTableToVector(std::vector<char> &v)
{
    std::generate_n(std::back_inserter(v), 95, [n=31]() mutable { return static_cast<char>(++n); });
}

void shuffleVector(std::vector<char> &v)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
}

void PasteTwoVectorsToTheMap(const std::vector<char>& key, const std::vector<char>& value, std::map<char, char>& m)
{
    std::transform(key.cbegin(), 
                   key.cend(), 
                   value.cbegin(), 
                   std::inserter(m, m.begin()),
                   [](char a, char b){return std::make_pair(a, b);});
}

std::map<char, char> makeUniqueCipherMap()
{
    std::vector<char> v1{};
    insertAsciiTableToVector(v1);
    std::vector<char> v2 = v1;
    shuffleVector(v2);
    std::map<char, char> m{};
    PasteTwoVectorsToTheMap(v1, v2, m);
    return m;
}

int main()
{
    std::map<char, char> map1 = makeUniqueCipherMap();
    return 0;
}