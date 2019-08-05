#include <iostream>
#include <random>
#include <numeric>
#include <vector>
#include <map>

std::vector<int> generateRand(const int& range, const int& number)
{
    std::random_device randDevice;
    std::mt19937 engine{randDevice()};
    std::uniform_int_distribution<> dist(0, range);
    std::vector<int> randValVec;
    randValVec.reserve(number);
    for (int i = 0; i < number; ++i)
    {
        randValVec.push_back(dist(engine));
    }
    return randValVec;
}

bool isPrime(const int& number)
{
    int numerOfTimes = {0};
    for(int i = 2; i <= number; ++i)
    {
        if(number%i==0)
            numerOfTimes++;
    }
    return  number >= 2 and (numerOfTimes == 1 or numerOfTimes == 0);
}

std::vector<int> generatePrime(const int& range)
{
    std::vector<int> primeVec(range);
    std::iota(primeVec.begin(), primeVec.end(), 0);
    for(auto i = primeVec.begin(); i != primeVec.end(); )
    {
        if(isPrime(*i)) i++;
        else primeVec.erase(i);
    }
    return primeVec;
}

std::map<int, std::vector<int>> assignPrimeToRand(std::vector<int> prime, std::vector<int> randVal)
{
    std::map<int, std::vector<int>> primeToValueMap{};
    for(const auto& element:prime)
    {
        primeToValueMap[element] = {};
        for(size_t i = 0; i < randVal.size(); ++i)
        {
            if((randVal[i]%element)==0)
                primeToValueMap[element].push_back(randVal[i]);
        }
    }
    return primeToValueMap;
}

std::map<int, std::vector<int>> removeEmptyKeys(std::map<int, std::vector<int>> myMap)
{
    for(auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        if(it->second.empty())
            myMap.erase(it);
    }
    return myMap;
}

void printVec(std::vector<int> number)
{
    for(const auto& elements:number)
    {
        std::cout << elements << " ";
    }
    std::cout << std::endl;
    std::cout << "size: " << number.size() << std::endl;
    std::cout << "capacity: " << number.capacity() << std::endl;
}

void printVecFromMap(std::vector<int> number)
{
    std::cout << "{";
    for(const auto& elements:number)
    {
        std::cout << elements << ", ";
    }
    std::cout << "}" << std::endl;
}

void printMap(std::map<int, std::vector<int>> map)
{
    for(const auto& elements:map)
    {
        std::cout << elements.first;
        printVecFromMap(elements.second);
    }
}

int main()
{
    std::cout << "Range of numbers to generate from, 0 to ";
    int M;
    std::cin >> M;
    std::cout << std::endl;
    std::cout << "Amount of random numbers to generate: ";
    int N;
    std::cin >> N;
    std::cout << std::endl;
    std::vector<int> testRand{generateRand(M,N)};
    printVec(testRand);
    std::cout << std::endl;
    std::vector<int> testPrime{generatePrime(M)};
    printVec(testPrime);
    std::cout << std::endl;
    std::map<int, std::vector<int>> testMap(assignPrimeToRand(testPrime, testRand));
    std::map<int, std::vector<int>> cleanMap(removeEmptyKeys(testMap));
    printMap(cleanMap);
    return 0;
}