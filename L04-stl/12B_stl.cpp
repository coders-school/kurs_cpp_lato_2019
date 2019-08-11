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
	
	std::for_each(myVector.begin(), myVector.end(), [&](auto& el)
	{
	std::for_each(primeVector.begin(), primeVector.end(), [&](auto& elPrime)
		{
			if (el%elPrime == 0)
			{
				if (primeMap.find(elPrime) == primeMap.end())
				{
					std::vector<int> v;
					v.push_back(el);
					primeMap.insert( std::pair<int, std::vector<int> >(elPrime, v));
				}
				else
				{
					auto foundP = primeMap.find(elPrime);
					foundP->second.push_back(el);
				}
			}
		}
		);
	}
	);
	
	std::cout<< "primeMap: "<< std::endl;
	showMap(primeMap);

	return 0;
}

/*
Give me N (how many values do You want): 20
Give me M (what range do You want 1...N?): 20

myVector before any changes: [ 13 11 6 8 4 8 13 1 0 5 8 4 15 2 15 17 16 13 11 5 ]

myVector after sort: [ 0 1 2 4 4 5 5 6 8 8 8 11 11 13 13 13 15 15 16 17 ]

Removing multiply numbers.
[ 0 1 2 4 5 6 8 11 13 15 16 17 ]

Erasing 0 and 1 from myVector.
[ 2 4 5 6 8 11 13 15 16 17 ]

Creating vector with prime numbers.
[ 2 3 5 7 11 13 17 19 ]

primeMap:
2 [ 2 4 6 8 16 ]
3 [ 6 15 ]
5 [ 5 15 ]
11 [ 11 ]
13 [ 13 ]
17 [ 17 ]
*/
