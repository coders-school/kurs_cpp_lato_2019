// Execrise 12.B (in groups):
// Divisors Finder

#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>

void printVector (const std::vector <int> &);
void printMap (const std::map<int,std::vector<int>> &);
bool checkIfIsNotPrime (int);
int creatingRandomNUmber (int);  
void checkIfIsDIvider (int, int, std::vector<int>);
   void function(int);


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
 
    std::vector<int> values(N, 0);
    srand(time(NULL));
    std::generate(values.begin(), 
                  values.end(), 
                  [M] () { return creatingRandomNUmber(M);});

    printVector(values);
   
    sort(values.begin(), values.end());
  
    std::vector<int> prime (values.begin(),values.end());
    prime.erase(std::unique(prime.begin(),prime.end()), prime.end());
    std::vector <int>::iterator it;
    it = std::remove_if(prime.begin(),
                        prime.end(),
                        [] (auto element) {return checkIfIsNotPrime(element);});
    prime = {prime.begin(),it};
    printVector(prime);
    std::cout<<"--------------------------------"<<std::endl;
    
    std::map<int,std::vector<int>> PrimeValues;
  
    for(auto elementM : prime)
    {
        std::vector<int> keyVal;
        for(auto it = values.begin(); it < values.end(); it++)
        {
            if(*it % elementM == 0 && *it != *(it-1)) 
                keyVal.push_back(*it);
        }
        PrimeValues.emplace(elementM,keyVal);
        keyVal.clear();
    }
    

   /*
     
    std::vector<int>::iterator iterator = prime.begin();
    std::for_each(prime.begin(), prime.end(), function);

    void function(int x)
    {
        std::vector<int> keyVal;
        std::for_each(values.begin(), 
                      values.end(), 
                      [](auto it){if (*it%x ==0) keyVal.push_back(it);});
        PrimeValues.emplace(x, kayVal);
        keyVal.clear();
    } 

*/
    printMap(PrimeValues);
    
    return 0;
}
// -----------------------------------------------------------
 int creatingRandomNUmber (int a)   
    {
        return rand()%(a+1);
    }
    
// -----------------------------------------------------------
 void checkIfIsDIvider (int a, int b, std::vector<int> v)   
    {
        if (a%b == 0)
            {v.push_back(a);}   
    }
// -----------------------------------------------------------

void printVector(const std::vector<int> &vec)
{
    std::transform(vec.begin(), 
                   vec.end(), 
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto & element){return element; });
    std::cout <<std::endl;
}
// -----------------------------------------------------------
void printMap (const std::map <int,std::vector<int>> & m)
{
    std::for_each(m.begin(), 
                  m.end(),
                  [](auto element) { std::cout << element.first <<"\t"; 
                  printVector(element.second); });

}   
// -----------------------------------------------------------
bool checkIfIsNotPrime (int number)
{
    static int sum = 0;
    sum = 0; 
    std::vector <int> vec(number, 0);
    std::iota(vec.begin(), vec.end(), 1) ;
    int vectorSize = vec.size();
    if (vectorSize <2) 
        return true;
    else 
    {
        std::for_each(vec.begin(),
                      vec.end(),
                      [vectorSize] (auto element) {if ((vectorSize)%element == 0){sum++ ;}});
        if (sum > 2) 
            return true;
        else 
            return false;   
    }
}
// -----------------------------------------------------------

