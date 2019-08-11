#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int M;
std::vector<int> vPrimeValues;
std::vector<int> vRandomValues;

bool isNumberPrime(int number)
{
    for(int a = 2; a < number; a++)
    {
        if (number % a == 0)
            return false;
    }
    return true;
}

void printPrimeFromRange(int M)
{
    for (int currentNum = 2; currentNum < M; currentNum++)
    {
        if (isNumberPrime(currentNum))
        {
            std::cout << currentNum << " ";
            vPrimeValues.emplace_back(currentNum);
        }
    }
    std::cout << '\n';
}

int generateRandomValues(int N)
{
    for(int i=1; i <= N; i++)
    {
        int rand = std::rand()%(M+1);
        std::cout << rand << " ";
        vRandomValues.emplace_back(rand);
    }
    std::cout << '\n';
}

void printUniqueValueFromVector (std::vector <int> v)
{
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
    for (auto el : v)
        std::cout << el << " ";
    std::cout << '\n';
}

void printValueFromMap (std::multimap<int,std::vector<int>> m)
{
     for(auto el : m)
    {
        std::cout << el.first << " -> ";
        printUniqueValueFromVector(el.second);
    }
}

int main(){
    srand(time(NULL));
    int N;

    std::cout << "Exercise 12B:" << '\n';
    std::cout << "Write M: "; std::cin >> M;
    std::cout << "Write N: "; std::cin >> N;
    std::cout << "All prime from 0 to M: ";
    printPrimeFromRange(M);
    std::cout << "N random values from 0 to M: ";
    generateRandomValues(N);

    std::multimap<int,std::vector<int>> mapPrimeToValue;
    for(auto el : vPrimeValues)
    {
        std::vector<int> vKeyValues;
        for(auto it = vRandomValues.begin(); it < vRandomValues.end(); it ++)
        {
            if(*it % el == 0)
             vKeyValues.push_back(*it);
        }
        mapPrimeToValue.emplace(el,vKeyValues);
        vKeyValues.clear();
    }
    printValueFromMap(mapPrimeToValue);

    return 0;
}
