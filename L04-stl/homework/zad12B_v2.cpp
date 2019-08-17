#include <iostream>
#include <iterator>
#include <random>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>

void printVector(const std::vector<unsigned>& v)
    {
        std::copy(v.cbegin(), v.cend(), std::ostream_iterator<unsigned>(std::cout, " "));
        std::cout << "\n";
    }

std::vector<unsigned> generateRandomNumbers(unsigned amount, unsigned minValue, unsigned maxValue)
{
    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<> dist(minValue, maxValue);
    std::vector<unsigned> output;
    std::generate_n(std::back_inserter(output), 
                    amount,
                    [&gen, &dist](){ return dist(gen); });
    return output;
}

std::vector<unsigned> generateConsecutiveIntegers(unsigned minValue, unsigned maxValue)
{
    std::vector<unsigned> integers;
    std::generate_n(std::back_inserter(integers),
                    maxValue-minValue+1,
                    [&minValue]() mutable { return minValue++; });
    return integers;
}

std::vector<unsigned> generatePrimeNumbers(unsigned maxValue)
{
    std::vector<unsigned> data = generateConsecutiveIntegers(2, maxValue);
    std::vector<unsigned>::iterator vItr = data.begin();
    unsigned currentValue;
    auto eratosthenesCrossOut = [&currentValue](unsigned x)
    { 
        if(x!=currentValue) 
            return x%currentValue == 0; 
        return false; 
    };
    for(unsigned i1 = 2; i1 <= static_cast<unsigned>(sqrt(maxValue)); ++i1)
    {
        currentValue = *vItr;
        data.erase(std::remove_if(data.begin(), data.end(), eratosthenesCrossOut), data.end());
        ++vItr;
    }
    return data;
}

std::map<unsigned, std::vector<unsigned>> createMapWithPrimeNumbersAndDividents(
    std::vector<unsigned>& primeNumbers, std::vector<unsigned> randomUnsignedNumbers)
{
    std::sort(randomUnsignedNumbers.begin(), randomUnsignedNumbers.end());
    std::vector<std::vector<unsigned>> dividentsVectors{};
    dividentsVectors.resize(primeNumbers.size());
    unsigned counter = 0;
    for(auto & element : primeNumbers)
    {
        std::copy_if(randomUnsignedNumbers.begin(),
                    randomUnsignedNumbers.end(),
                    std::back_inserter(dividentsVectors[counter]),
                    [element](unsigned x){ if(x!=element) return (x%element == 0 and x != 0); return false; });        
        dividentsVectors[counter].erase(
            std::unique(dividentsVectors[counter].begin(), dividentsVectors[counter].end()),
            dividentsVectors[counter].end());
        ++counter;
    }
    std::map<unsigned, std::vector<unsigned>> output{};
    counter = 0;
    for(auto & element : primeNumbers)
    {
        output[element] = dividentsVectors[counter];
        ++counter;
    }        
    return output;
}

void printMap(std::map<unsigned, std::vector<unsigned>>& input)
    {
        std::for_each(input.cbegin(), 
                      input.cend(), 
                      [](std::pair<unsigned, std::vector<unsigned>> p)
                      { 
                        std::cout << "key: " << p.first << ",  value: ";
                        printVector(p.second);
                        std::cout << "\n"; 
                      });
    }

int main()
{
    std::cout << "**  Prime numbers and their dividents generator  **\n";
    std::cout << "Enter maximum prime number value (M): ";
    unsigned M;
    std::cin >> M;
    std::cout << "Enter amount of generated random integers (from 0 to M) (N): ";
    unsigned N;
    std::cin >> N;
    
    std::vector<unsigned> randomNumbers = generateRandomNumbers(N, 0, M);
    std::vector<unsigned> primeNumbers = generatePrimeNumbers(M);
    std::map<unsigned, std::vector<unsigned>> map = createMapWithPrimeNumbersAndDividents(primeNumbers, randomNumbers);
    
    std::cout << "\nPrinting map with prime numbers as keys and dividents as values: \n\n";
    printMap(map);
    return 0;
}