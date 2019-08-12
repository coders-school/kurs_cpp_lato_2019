#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> vPrimeValues;
vector<int> vRandomValues;
int M;

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
            cout << currentNum << " ";
            vPrimeValues.emplace_back(currentNum);
        }
    }
    cout<<endl;
}

int generateRandomValues(int N)
{    
    for(int i=1; i <= N; i++)
    {
        int rand1 = rand()%(M+1);
        cout << rand1 << " ";
        vRandomValues.emplace_back(rand1);
    }
    cout << endl;
}

void printUniqueValueFromVector (vector <int> v)
{
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    for (auto el : v)
        cout << el << " ";
    cout << endl;
}

void printValueFromMap (multimap<int,vector<int>> m)
{
     for(auto el : m)
    {
        cout << el.first << " -> ";
        printUniqueValueFromVector(el.second);
    }
}

int main(){
    srand(time(NULL));
    int N;
    cout << "Enter M: "; cin >> M;
    cout << "Enter N: "; cin >> N;
    cout << "All prime between 0 to M: ";
    printPrimeFromRange(M);
    cout << "N random values between 0 to M: ";
    generateRandomValues(N);

    multimap<int,vector<int>> mapPrimeToValue;
    for(auto el : vPrimeValues)
    {
        vector<int> vKeyValues;
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