#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>


int getRandom(int m)
{
    return random() % m;
}

int isPrime(int n)
{
    int i, m=0, flag=0;  
    m = n / 2;
    for(i = 2; i <= m; i++)  
    {  
        if(n % i == 0)  
        {  
            flag=1;  
            break;  
        }  
    }  
    if (!flag)  
        return n; 
    else
        return 0;  
}
std::vector<int> returnDividers(std::vector<int> values, int it)
{
    std::vector<int> vec = {};
    std::transform(values.begin(), values.end(), values.begin(), [&](const auto& iter){
        if(!(iter % it))
        vec.emplace_back(iter);
        return 0;
    });
    return vec;
}
void printDivisorOfValue(int n, int m)
{
    std::vector<int> values(n);
    std::generate(values.begin(), values.end(), [&] () mutable { return random() % m; });
    std::map<int, std::vector<int> > mapa = {};
    std::vector<int> prime(n);
    std::generate(prime.begin(), prime.end(), [p = 1] () mutable {++p; return isPrime(p); });
    prime.erase(std::remove(prime.begin(), prime.end(), 0), prime.end());
    prime.resize(m);
    values.erase(std::remove(values.begin(), values.end(), 0), values.end());
    std::sort(values.begin(), values.end());
    auto last = std::unique(values.begin(), values.end());
    values.erase(last, values.end());
    std::transform(prime.begin(), prime.end(), prime.begin(), [&](auto& it){
        mapa.insert({it, returnDividers(values, it)});
        ++it;
        return 0;
    });
    for(auto it = mapa.begin(); it != mapa.end(); ++it)
    {
        std::cout << it->first << ": ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            std::cout << *it2 << " "; 
        }  
        std::cout << std::endl;
    }
}

int main()
{
    int n,m;
    n = 745;
    m = 13;
    printDivisorOfValue(n,m);
    return 0;
}

