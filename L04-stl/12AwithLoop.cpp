#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

std::string decrypt(std::string result, int randNumber, std::string word){
    std::string decryptedWord;
    auto itR = result.begin();
    auto itW = word.begin();
    for(itR,itW ; itR<result.end() ; ++itR,++itW)
    {
        if(static_cast<int>(*itR)+randNumber == static_cast<int>(*itW))
        {
            int number;
            number = static_cast<int>(*itR) + randNumber;
            decryptedWord.push_back(number);
        }
        else
        {
            int number;
            number = static_cast<int>(*itR) - randNumber;
            decryptedWord.push_back(number);
        }
   }
    return decryptedWord;
}

std::string encrypt(std::string word, int randNumber){
    std::string encryptedWord;
    for(auto element : word)
    {
        if(static_cast<int>(element) <= 78)
        {
            int number;
            number = static_cast<int>(element) + randNumber;
            encryptedWord.push_back(number);
        }
        else
        {
            int number;
            number = static_cast<int>(element) - randNumber;
            encryptedWord.push_back(number);
        }
   }
    return encryptedWord;
}

int main(){
    srand( time( NULL ) );
    unsigned int randNumber = std::rand()%45;
    std::string word;
    std::cout << "Write text to encrypt: ";
    std::getline(std::cin,word);
    std::cout << "Encrypted word: " << encrypt(word, randNumber) << '\n';
    std::cout << "Decrypted word: " << decrypt(encrypt(word, randNumber), randNumber,word) << '\n';
    return 0;
}
