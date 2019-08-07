#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>


void showVector(auto& v)
{
	for (auto& e : v)
	{
		std::cout<< e << " ";
	}
	std::cout<< std::endl;
}


void fillVector(auto& v, int N, int M)
{
	srand(time(NULL));

	for (size_t i=0; i<N; i++)
	{
		v.push_back(rand()%M);
	}
}


int isPrime(int n)
{
	int tempN = n;
	int ch =0;
	while (tempN > 1)
	{
		tempN--;
		if (n%tempN == 0)
		{
			ch++;
		}
	}
	return ch;
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

	std::cout<< "myVector before any changes: ";
	showVector(myVector);

	std::cout<< "myVector after sort: ";
	std::sort(myVector.begin(), myVector.end());
	showVector(myVector);

	std::cout<< "Removing multiply numbers. " << std::endl;
	auto uniq = std::unique(myVector.begin(), myVector.end());
	myVector.erase(uniq, myVector.end());
	showVector(myVector);

	std::cout<< "Erasing 0 and 1 from myVector." <<std::endl;
	myVector.erase(std::remove(myVector.begin(), myVector.end(), 0), myVector.end());
	myVector.erase(std::remove(myVector.begin(), myVector.end(), 1), myVector.end());
	showVector(myVector);

	myVector.shrink_to_fit();

	std::cout<< "\nCreating vector with prime numbers." << std::endl;
	std::vector<int> primeVector;
	for (size_t i=2; i < M; i++)
	{
		if (isPrime(i))
		{
			primeVector.push_back(i);
		}
	}
	showVector(primeVector);

	std::map<int, std::vector<int>> primeMap;

	return 0;
}
