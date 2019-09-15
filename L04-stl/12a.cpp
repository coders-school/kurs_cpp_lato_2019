#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>
#include <array>


void encryption(std::map<char , char> m, std::string stringToCiphering)
{
    std::cout << stringToCiphering << "\n";
    std::transform(stringToCiphering.begin(), stringToCiphering.end(), stringToCiphering.begin(), [&](const auto& iter){
        auto printIterator = m.find(iter);
        std::cout << printIterator->second;
        return 0;
    });
    std::cout << "\n";
}

void decryption(std::map<char, char> m, std::string stringToCiphering)
{
    std::cout << stringToCiphering << "\n";
    for(const auto& element : stringToCiphering)
    {
        auto result = std::find_if(m.begin(), m.end(), [element](const auto& mo){
            return mo.second == element; 
        });
        std::cout << result->first;
    }
    std::cout << "\n"; 
}
 
int main()
{ 
    std::vector<char> letter = {};
    std::vector<char> cipher = {};
    letter.shrink_to_fit();
    letter.resize(95);
    std::iota(letter.begin(), letter.end(), 32);
    std::copy(letter.begin(), letter.end(), std::back_inserter(cipher));
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cipher.begin(), cipher.end(), g);
    std::map<char, char> m = {};
    auto iter_cipher = cipher.begin();
    auto iter_letter = letter.begin();
    std::generate(letter.begin(), letter.end(), [&](){ m.insert({*iter_letter, *iter_cipher});
    ++iter_letter;
    ++iter_cipher;
    return 0;});
    std::string stringToCiphering;
    std::cout << "Enter the message to encrypt or decrypt:" << "\n";
    std::getline(std::cin,stringToCiphering);
    std::cout << stringToCiphering << "\n";
    char choice;
    std::cout << "For encryption enter 1, for decription enter 2." << "\n";
    if(std::cin >> choice, choice == '1')
        encryption(m, stringToCiphering);
    else if(choice, choice == '2')
        decryption(m, stringToCiphering);
    else
        std::cout << "Wrong choice." << "\n"; 
    

       

   return 0;
}