#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>


void showVector(const auto& v)
{
	std::cout<< "[ ";
	/*
	for (auto& e : v)
	{
		std::cout<< e << " ";
	}
	*/
	std::cout<< "]"<< std::endl;;
}

void showMap (const auto& m)
{
	/*
	for (auto [first, second] : m)
	{
		std::cout<< first<< " -> ";
		showVector(second);
	}
	*/
}


void fillVector(auto& v, int N, int M)
{
	srand(time(NULL));

	/*
	for (size_t i=0; i<N; i++)
	{
		v.push_back(rand()%M);
	}
	*/
}


bool isPrime(int n)
{
	int tempN = n;
	/*
	while (tempN > 2)
	{
		tempN--;
		if (n%tempN == 0)
		{
			return false;
		}
	}
	*/
	return true;
}


void fillPrimeVector(auto& v, int M)
{
	/*
	for (size_t i=2; i < M; i++)
	{
		if (isPrime(i))
		{
			v.push_back(i);
		}
	}
	*/
}


int main ()
{
	int N;
	int M;

	std::cout<< "Give me N (how many values do You want): ";
	std::cin >> N;

	std::cout<< "Give me M (what range do You want 1...N?): ";
	std::cin >> M;

	std::vector<int> myVector;
	myVector.reserve(N);
	fillVector(myVector, N, M);

	std::cout<< "\nmyVector before any changes: ";
	showVector(myVector);

	std::cout<< "\nmyVector after sort: ";
	std::sort(myVector.begin(), myVector.end());
	showVector(myVector);

	std::cout<< "\nRemoving multiply numbers. " << std::endl;
	auto uniq = std::unique(myVector.begin(), myVector.end());
	myVector.erase(uniq, myVector.end());
	showVector(myVector);

	std::cout<< "\nErasing 0 and 1 from myVector." <<std::endl;
	myVector.erase(std::remove(myVector.begin(), myVector.end(), 0), myVector.end());
	myVector.erase(std::remove(myVector.begin(), myVector.end(), 1), myVector.end());
	showVector(myVector);

	myVector.shrink_to_fit();

	std::cout<< "\nCreating vector with prime numbers." << std::endl;
	std::vector<int> primeVector;
	fillPrimeVector(primeVector, M);
	showVector(primeVector);
	std::cout<< std::endl;


	std::map<int, std::vector<int>> primeMap;

	/*
	for (auto it = myVector.begin(); it != myVector.end(); it++)
	{
		for (auto itPrime = primeVector.begin(); itPrime != primeVector.end(); itPrime++)
		{
			if (*it%*itPrime == 0)
			{
				if (primeMap.find(*itPrime) == primeMap.end())
				{
					std::vector<int> v;
					v.push_back(*it);
					primeMap.insert( std::pair<int, std::vector<int> >(*itPrime, v));
				}
				else
				{
					auto foundP = primeMap.find(*itPrime);
					foundP->second.push_back(*it);
				}
			}
		}
	}
	*/
	std::cout<< "primeMap: "<< std::endl;
	showMap(primeMap);

	return 0;
}


/* output:
Give me N (how many values do You want): 10
Give me M (what range do You want 1...N?): 20

myVector before any changes: [ 4 12 2 7 15 18 2 0 5 19 ]

myVector after sort: [ 0 2 2 4 5 7 12 15 18 19 ]

Removing multiply numbers.
[ 0 2 4 5 7 12 15 18 19 ]

Erasing 0 and 1 from myVector.
[ 2 4 5 7 12 15 18 19 ]

Creating vector with prime numbers.
[ 2 3 5 7 11 13 17 19 ]

primeMap:
2 -> [ 2 4 12 18 ]
3 -> [ 12 15 18 ]
5 -> [ 5 15 ]
7 -> [ 7 ]
19 -> [ 19 ]
*/
