#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

char int2char(int myInt )
 {
     switch(myInt)
     {
         case 0: return '0';
		 case 1: return '1';
         case 2: return '2';
         case 3: return '3';
         case 4: return '4';
         case 5: return '5';
         case 6: return '6';
         case 7: return '7';
         case 8: return '8';
         case 9: return '9';
     }
 }

int main ()
{
	std::vector<char> chVector;
	std::string myString {"abcd"};

	srand(time(NULL));
	int	random_int = (rand()%10);
	chVector.push_back(int2char(random_int));

	for (size_t i=0; i<myString.size(); i++)
	{
		chVector.push_back(myString[i]);	
	}	

	std::map<int, char> myMap;
	for (int i=0;i<=myString.size();i++)
	{
		myMap.insert(myMap.begin(),std::pair<int,char>(i,chVector[i]));
	}

	for (size_t i=1; i<myMap.size(); i++)
	{		
	( int myMap.at(i)+=random_int) ;
	}

	for (auto& [first, second] : myMap)
	{
		std::cout<< first << " " << second << std::endl;
	}	



	return 0;
}
