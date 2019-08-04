#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <chrono>
#include <map>
#include <forward_list>
#include <functional>
#include <algorithm>
#include <cstdlib>

void printElements(const auto& a)
{
	for (auto element : a)
	{
		std::cout<< element << " ";
	}
	std::cout<<std::endl;
}


void printMapElements(const auto& myMap)
{
	for (auto& [first, second] : myMap)
	{
		std::cout<< first << " -> " << second << ", ";
	}
	std::cout<<std::endl;
}


void printStart(const int numb)
{
	std::cout<<"\n-----------------------------------------------";
	std::cout<<"\nExercise number "<< numb << " -----------------------------\n\n";
}


void printEnd(int numb)
{
	std::cout<<"\nEnd of exercise number "<< numb << " ----------------------\n";
	std::cout<<"-----------------------------------------------\n\n";
}


void exercise1(const int number)
{
	printStart(number);

	std::array<int, 10> myArray {5,5,5,6,5,5,6,5,5,5};
	std::cout<< "myArray: ";
	printElements(myArray);

	myArray.fill(5);
	std::cout<< "myArray: ";
	printElements(myArray);

	myArray[4] = 3;
	std::cout<<"Element 4 (0,1,2,3,4) has been changed to 3."<<std::endl;
	std::cout<< "myArray: ";
	printElements(myArray);

	std::array<int, 10> mySndArray;
	mySndArray.fill(11);
	std::cout<< "mySndArray: ";
	printElements(mySndArray);

	std::cout<<"Arrays after swap:"<<std::endl;
	myArray.swap(mySndArray);
	std::cout<< "myArray: ";
	printElements(myArray);

	std::cout<< "mySndArray: ";
	printElements(mySndArray);

	printEnd(number);
}


void exercise2(const int number)
{
	printStart(number);

	std::vector<int> myVector{1,2,4,5,6};
	std::cout<<"myVector: ";
	printElements(myVector);

	std::vector<int>::iterator it = myVector.begin();
	std::cout<<"First element will be erased."<<std::endl;
	myVector.erase(it);
	std::cout<<"myVector: ";
	printElements(myVector);

	std::cout<<"Number 5 will be added at the end" <<std::endl;
	myVector.push_back(5);
	std::cout<<"myVector: ";
	printElements(myVector);

	std::cout<<"Number 12 will be added by emplace function." <<std::endl;
	it = myVector.begin();
	myVector.emplace(it, 12);
	std::cout<<"myVector: ";
	printElements(myVector);

	std::cout<<"myVector size: " << myVector.size() <<std::endl;
	std::cout<<"myVector max_size: " << myVector.max_size() <<std::endl;

	std::cout<<"myVector after clear function:"<<std::endl;
	myVector.clear();
	std::cout<<"myVector: ";
	printElements(myVector);
	std::cout<<"myVector size after clear(): " << myVector.size() <<std::endl;

	printEnd(number);
}


void exercise3(const int number)
{
	printStart(number);

	std::vector<int> myVector;
	std::cout << "Size() of myVector: " << myVector.size() << std::endl;
	std::cout << "Capacity() of myVector: " << myVector.capacity() << std::endl;

	myVector.resize(10);
	std::fill(myVector.begin(), myVector.end(),  5);

	std::cout << "myVector: ";
	printElements(myVector);
	std::cout << "Size() of myVector: " << myVector.size() << std::endl;
	std::cout << "Capacity() of myVector: " << myVector.capacity() << std::endl;

	myVector.reserve(20);
	std::cout<< "Reservation for at least 20 elements has been deployed." <<std::endl;
	std::cout << "Size() of myVector: " << myVector.size() << std::endl;
	std::cout << "Capacity() of myVector: " << myVector.capacity() << std::endl;

	myVector.shrink_to_fit();
	std::cout<< "myVector after activation of shrink_to_fit function: " <<std::endl;
	std::cout << "Size() of myVector: " << myVector.size() << std::endl;
	std::cout << "Capacity() of myVector: " << myVector.capacity() << std::endl;

	printEnd(number);
}


void exercise4(const int number)
{
	printStart(number);
	//list
	std::list<int> myList;
	int i=0;

	auto start = std::chrono::high_resolution_clock::now();
	while(i < 1000000)
	{
		myList.push_back(i);
		i++;
	}
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = stop - start;
	std::cout<< "List -> Time of adding 1000000 elements: " << elapsed.count()<< std::endl;

	int length = myList.size();
	std::list<int>::iterator it = myList.begin();
	start = std::chrono::high_resolution_clock::now();
	for (size_t i=0; i< length/2; i++)
	{
		it++;	
	}
	stop = std::chrono::high_resolution_clock::now();
	elapsed = stop - start;
	std::cout<<"List -> 500 000 element: "<< *it << std::endl; 
	std::cout<< "List -> Access time to 500000 element: " << elapsed.count() << std::endl;
	
	//vector
	std::vector<int> myVector;
	i=0;
	start = std::chrono::high_resolution_clock::now();
	while (i < 1000000)
	{
		myVector.push_back(i);
		i++;
	}
	stop = std::chrono::high_resolution_clock::now();
	elapsed = stop - start;
	std::cout<< "Vector -> Time of adding 1000000 elements: " << elapsed.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::cout<<"Vector -> 500 000 element: " << myVector[500000] << std::endl;
	stop = std::chrono::high_resolution_clock::now();
	elapsed = stop - start;
	std::cout<< "Vector -> Access time to 500000 element: " << elapsed.count() << std::endl;
	elapsed *= 1000;
	std::cout<< "Vector -> Time multiplying by 1000, to better show time: " << elapsed.count() << std::endl;

	printEnd(number);
}


void exercise5(const int number)
{
	printStart(number);

	std::cout<< "Adding pairs to map."<<std::endl;
	std::map<int, std::string> myMap {{1,"one"}, {2,"two"}, {3,"thr"}, {4,"four"}, {5,"five"}};
	std::cout<< "myMap: ";
	printMapElements(myMap);
	std::cout<< "Adding new pair: 3 -> three"<<std::endl;
	myMap.insert( std::pair<int, std::string> (3, "three") );
	std::cout<< "myMap: ";
	printMapElements(myMap);	
	std::cout<<"Pair 3 -> three wasn't added, because key 3 is already exist in map."<<std::endl;

	std::map<int, std::string>::iterator it = myMap.begin();
	it = myMap.find(3);
	if (it != myMap.end())
	{
		std::cout<< "Key 3 has been found: ";
		std::cout<< it->first << " -> " << it->second << std::endl;
		std::cout<< "Updating second key in pair from thr to three" << std::endl;
		it->second = "three";
	}
	else
	{
		std::cout<< "There is no 3 key in pairs. New pair of 3->three will be added to map." <<std::endl;
		myMap.insert({3, "three"});
	}
	std::cout<< "myMap: ";
	printMapElements(myMap);	
	
	std::cout<< "Pair with key 5 will be erase from map container." <<std::endl;
	myMap.erase(5);
	std::cout<< "myMap: ";
	printMapElements(myMap);	

	std::cout<< "I'm looking if there is any pair, which contain key=4 " <<std::endl;
	for (auto it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->first == 4)
		{
			std::cout<<"I found it;): " << it->first << " -> " << it->second << std::endl;
		}
	}

	if (myMap.find(7) == myMap.end())
	{
		std::cout<< "Unfortunately, there isn't here, which You're looking for." <<std::endl;
	}

	printEnd(number);
}


void exercise6(const int number)
{
	printStart(number);

	std::forward_list<int> myForwardList {3,4,5,7,8,4,12,0};
	std::cout<< "myForwardList: ";
	printElements(myForwardList);
	std::forward_list<int>::iterator itBegin = myForwardList.begin();
	auto itEnd = myForwardList.end();

	std::cout<< "There isn't size() function in forward_list. " << std::endl;
	std::cout<< "In this case std::distance has been used." << std::endl;
	std::cout<< "Size of myForwardList: " << std::distance(itBegin, itEnd) << std::endl;

	int iter = 0;
	for (itBegin; itBegin != itEnd; itBegin++)
	{
		if (iter==4)
		{
			std::cout<< "Fifth element in forward_list is: " << *itBegin << std::endl;
			std::cout<< "Distnace form beggining to this iterator is: " << std::distance(myForwardList.begin(), itBegin) << std::endl;
			break;
		}
		iter++;
	}

	printEnd(number);
}


//to exercice7
class Multiply
{
public:
	Multiply() {};
	int operator()(int x)
	{
		return std::multiplies<int>() (x, 5);
	}
};

int multiplyFun(int x)
{
	return std::multiplies<int>() (x, 5);
};



void exercise7(const int number)
{
	printStart(number);

	std::function<int(int)> result = [](int x) {return x*5;};
	std::cout << "Lambda: X before = 5, X after = " << result(5) << std::endl;
	std::function<int()> multi5 = std::bind(&multiplyFun, 5);
	std::cout<< "std::bind -> multiplyFun: X before = 5, X after = "<< multi5() << std::endl;	
	std::function<int(int)> multi5F = Multiply();
	std::cout<< "Functor  Multiply(): X before = 5, X after = "<< multi5F(5) << std::endl;	
	std::cout<< "Functor  Multiply(): X before = 11, X after = "<< multi5F(11) << std::endl;	

	printEnd(number);
}


//to exercices8
class AbsInt
{
public:
	AbsInt() {};
	int operator()(int a, int b)
	{
		return std::abs(a) < std::abs(b);
	}
};

void exercise8(const int number)
{
	printStart(number);

	std::array<double, 5> myArray {5.0, 4.0, 7.9, -8.22, 0.4};
	std::cout<< "myArray: ";
	printElements(myArray);
	std::cout<< "Sorted by lambda: ";
	std::sort(myArray.begin(), myArray.end(), [](int a, int b) {return std::abs(a)< std::abs(b);});
	printElements(myArray);

	std::cout<< "Sorted by functor:";
	std::sort(myArray.begin(), myArray.end(), AbsInt());
	std::cout<< "myArray: ";
	printElements(myArray);

	printEnd(number);
}



int main (int argc, char* argv[])
{
	exercise1(1);
	exercise2(2);
	exercise3(3);
	exercise4(4);
	exercise5(5);
	exercise6(6);
	exercise7(7);
	exercise8(8);

	return 0;
}
