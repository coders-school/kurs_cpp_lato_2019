#include <iostream>
#include <random>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> generateRand(const int range, const int number)
{
    std::random_device randDevice;
    std::mt19937 engine{randDevice()};
    std::uniform_int_distribution<> dist(0, range);
    std::vector<int> randValVec;
    randValVec.reserve(number);
    //std::for_each(randValVec.begin(), randValVec.end(), )   [&](){}
    for (int i = 0; i < number; ++i)
    {
        randValVec.push_back(dist(engine));
    }
    return randValVec;
}

bool isPrime(const int number)
{
    int numerOfTimes = {0};
    std::vector<int> numberN(number);
    std::iota(numberN.begin(), numberN.end(),1);
    for_each(numberN.begin(), numberN.end(), [&](int x){if (number % x == 0) numerOfTimes +=1;});

   return (numerOfTimes == 2);
}

std::vector<int> generatePrime(const int range)
{
    std::vector<int> primeVec(range+1);
    std::iota(primeVec.begin(), primeVec.end(), 0); // UGLY COMMENT - cannot start with 2, input is 0-range. If range is 0-2 and vec filled with 2,3,4 - there is a prime '3' out of range 0-2. isBool takes 0 and 1 out of equation
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
            if(randVal[i]==0) continue;
            else if((randVal[i]%element)==0)
                {primeToValueMap[element].push_back(randVal[i]);}
        }
    }
    return primeToValueMap;
}
/* use with remove_if
void removeEmptyKeys(std::map<int, std::vector<int>>& myMap) // does not always remove keys with empty values? wut??? for example - prime 41, 31, 11, even if empty, isn't removed
{
    for(auto it = myMap.begin(); it != myMap.end(); )
    {
        if(it->second.empty())
            myMap.erase(it);
        else it++;
    }
}
*/
void printVec(const std::vector<int>& number)
{
    for(const auto& elements:number)
    {
        std::cout << elements << " ";
    }
    std::cout << std::endl;
    std::cout << "size: " << number.size() << std::endl;
    std::cout << "capacity: " << number.capacity() << std::endl;
}

void printVecFromMap(const std::vector<int>& number)
{
    std::cout << " {";
    for(const auto& elements:number)
    {
        std::cout << elements << " ";
    }
    std::cout << "}" << std::endl;
}

void printMap(const std::map<int, std::vector<int>>& map)
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
    //removeEmptyKeys(testMap);
    printMap(testMap);
    return 0;
}