#include <iostream>
#include <array>
#include <vector>
#include <list>

void printElements(const auto& a)
{
	for (auto element : a)
	{
		std::cout<< element << " ";
	}
	std::cout<<std::endl;
}

void printStart(int numb)
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

void exercise4(const int number)
{
	printStart(number);
	//list
	std::list<int> myList;
	int i=0;

	while(i < 1000000)
	{
		myList.push_back(i);
		i++;
	}
	std::cout<< "List -> Time of adding 1000000 elements: " << std::endl;

	int length = myList.size();
	std::list<int>::iterator it = myList.begin();
	for (size_t i=0; i< length/2; i++)
	{
		it++;	
	}
	std::cout<<"List -> 500 000 element: "<< *it << std::endl; 
	std::cout<< "List -> Access time to 500000 element: " << std::endl;
	//vector
	
	std::vector<int> myVector;
	i=0;
	while (i < 1000000)
	{
		myVector.push_back(i);
		i++;
	}
	std::cout<< "Vector -> Time of adding 1000000 elements: " << std::endl;

	std::cout<<"Vector -> 500 000 element: " << myVector[500000] << std::endl;
	std::cout<< "Vector -> Access time to 500000 element: " << std::endl;

	printEnd(number);
}


int main (int argc, char* argv[])
{
	exercise1(1);
	exercise2(2);

	exercise4(4);

	return 0;
}
