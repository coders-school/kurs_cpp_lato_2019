#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>


void fillMap(std::map<char, int>& myMap, std::string& myString)
{
	myMap.clear();
	for (size_t i=0; i<myString.size(); i++)
	{
		myMap.insert(myMap.begin(),std::pair<char,int>(myString[i], int(myString[i])));
	}
}


std::string encrypt(std::map<char, int>& myMap, int key, std::string& secretString)
{	
	fillMap(myMap, secretString);
	std::string secret = "";
	for (auto it= myMap.begin(); it !=myMap.end(); ++it)
	{
		secret += char(myMap[it->second]+key);
	}
	secretString = secret;
	return secret;
}


std::string decrypt(std::map<char, int>& myMap, int key, std::string& secretString)
{
	key *= -1;
	return encrypt(myMap, key, secretString);
}


int main ()
{
	srand(time(NULL));
	int key = (rand()%10)+1;

	std::map<char, int> myMap;
	std::string secretString {"abcde"}; // string will be downloaded from txt file

	std::cout<< "Orignal sentence: " << secretString << std::endl;
	std::cout<< "Sentense after encryption: " << encrypt(myMap, key, secretString) << std::endl;
	std::cout<< "Sentense after decryption: " << decrypt(myMap, key, secretString) << std::endl;
	
	return 0;
}
