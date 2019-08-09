// Execrise 12.B (in groups):
// Divisors Finder

#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <algorithm>

void printVector (std::vector <int>);
void printMap (std::map<int,std::vector<int>>);
bool checkIfIsPrime (int);

int main()
{
    int N = 0, M = 0;
    std::cout << "Program generate N numbers from 0 to M value range" << std::endl;
    std::cout << "  As the output You can see Prime -> Values map" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << " - How many numbers you want to generate: ";
    std::cin >> N;
    std::cout << " - Numbers will by generated from 0 to value: ";
    std::cin >> M;
 
    std::vector<int> values;
    srand(time(NULL));
    for (int it = 0; it < N; it++)
        values.push_back(rand()%(M+1));
    printVector(values);
    sort(values.begin(), values.end());
    
    std::vector<int> prime;
    for (int it = 0; it < M; it++)
    {
        if(checkIfIsPrime(it))
            prime.push_back(it);
    }
    printVector(prime);
    
    std::map<int,std::vector<int>> PrimeValues;
    for(auto elementM : prime)
    {
        std::vector<int> keyVal;
        for(auto it = values.begin(); it < values.end(); it ++)
        {
            if(*it % elementM == 0 && *it != *(it-1)) 
             keyVal.push_back(*it);
             // drugi warunek wyklucza przypisanie do keyVal 0 i duplikownia liczb (ponieważ
             // wektor values jest posortowany) 

        }
        PrimeValues.emplace(elementM, keyVal);
        keyVal.clear();
    }

    printMap(PrimeValues);
    return 0;
}

void printVector (std::vector <int> vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << std::endl;
}

void printMap (std::map<int,std::vector<int>> m)
{
     for(auto element : m)
    {
        std::cout << element.first << "\t";
        printVector(element.second);
    }
}

bool checkIfIsPrime (int number)
{
    if (number <2) 
        return false;
    else 
    {
        for (int i=2; i < number; i++)
        {
            if (number%i == 0) 
                return false;
        }
        return true;  
    }
}


