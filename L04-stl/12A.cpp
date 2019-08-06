#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

void encrypt(std::map<char, int>& myMap, int key)
{
	for (auto it= myMap.begin(); it !=myMap.end(); ++it)
	{
		myMap[it->second] += key;
		myMap[it->first] = char(myMap[it->second]);		
	}
}


void decrypt(std::map<char, int>& myMap, int key)
{
	key *= -1;
	encrypt(myMap, key);
}


void printElements(auto& map)
{
	for (auto& [first, second] : map)
	{
		std::cout<< first << " " << second<< std::endl;
	}
}

int main ()
{
	std::vector<char> chVector;
	std::string secretString {"abcd"}; // string will be downloaded from txt file

	srand(time(NULL));
	int	key = (rand()%10);

	std::cout<< "Key: " << key << std::endl;

	std::map<char, int> myMap;
	for (size_t i=0; i<secretString.size(); i++)
	{
		myMap.insert(myMap.begin(),std::pair<char,int>(secretString[i], int(secretString[i])));
	}

	std::cout<< "myMap: " <<std::endl;
	printElements(myMap);
	std::cout << std::endl;

	std::cout<< "Encryption: " << std::endl;
	encrypt(myMap, key);
	printElements(myMap);


	return 0;
}
