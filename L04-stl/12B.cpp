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
	showVector(myVector);

	std::cout<< "myVector after sort: ";
	std::sort(myVector.begin(), myVector.end());
	showVector(myVector);

	std::map<int, std::vector<int>> primeMap;

	return 0;
}
