#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>

void fillMap(std::map<char, int>& setOfCharInt, const std::string& cipherText)
{
	setOfCharInt.clear();
	for (size_t i=0; i<cipherText.size(); i++)
	{
		setOfCharInt.insert(std::begin(setOfCharInt),std::pair<char,int>(cipherText[i], static_cast<int>(cipherText[i])));
	}
}


std::string encrypt(std::map<char, int>& myMap, const int key, std::string& secretString)
{	
	fillMap(myMap, secretString);
	std::string secret = "";
	for (auto it= myMap.begin(); it !=myMap.end(); ++it)
	{
		secret += static_cast<char>(myMap[it->second]+key);
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
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(1,10);
	int key = distribution(generator);

	std::string secretString="";
	std::ifstream myFile ("toEncrypt.txt");
	if (myFile.is_open())
	{
		getline(myFile, secretString);
		myFile.close();
	}
	else
	{
		std::cout<< "I'm unable open this file." <<std::endl;
	}

	std::map<char, int> myMap;

	std::cout<< "Orignal sentence: " << secretString << std::endl;
	std::cout<< "Sentense after encryption: " << encrypt(myMap, key, secretString) << std::endl;

	std::ofstream myFileDe ("decrypt.txt");
	if (myFileDe.is_open())
	{
		myFileDe << secretString << std::endl;
	}
	else
	{
		std::cout<< "There is a problem with file, i can't write into." << std::endl;
	}

	std::cout<< "Sentense after decryption: " << decrypt(myMap, key, secretString) << std::endl;
	
	return 0;
}
