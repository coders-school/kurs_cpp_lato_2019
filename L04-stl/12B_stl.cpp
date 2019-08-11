#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>


void showVector(auto& v)
{
	std::cout<< "[ ";
	std::for_each( v.begin(), v.end(), [](int& el){std::cout<<el<<" ";});
	std::cout<< "]"<< std::endl;;
}

void showMap (auto& m)
{
	std::for_each( m.begin(), m.end(), [=](auto& el)
					{
						std::cout<<el.first<<" "; 
						showVector(el.second);
					}
					);
}


void push(auto& v, int n)
{
	v.emplace_back(n);
}

void fillVector(auto& v, int N, int M)
{
	srand(time(NULL));
	std::vector<int> n(N);
	std::for_each( n.begin(), n.end(), [&](int& el)
					{
						v.push_back(rand()%M);
					}
					);
}


bool isPrime(int N)
{
	std::vector<int> n(N);
    int counter = N;
	bool state = true;	
	std::for_each(n.begin(), n.end(), [&](int& el)
					{
						counter--;
						if ( (counter > 1) && (N%counter == 0) )
						{
							state = false;
						}
					}
					);

	return state;
}


void fillPrimeVector(auto& v, int M)
{
	std::vector<int> m(M);
	int counter = 1;
	std::for_each( m.begin(), m.end(), [&](int& el)
                 {
				 	counter++;
				 	if ( isPrime(counter) )
					{
                    	v.push_back(counter);
					}
                 }
                 );
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

