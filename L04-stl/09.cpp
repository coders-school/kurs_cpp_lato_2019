#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

std::string sentence;

bool isPali(std::string sentence)
{
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ' '), sentence.end());
    auto iterators = std::mismatch(sentence.begin(), sentence.end(), sentence.rbegin());
    return(iterators.first == sentence.end() && iterators.second == sentence.rend());
}

int main()
{
        std::cout<<"Write a sentence to check: ";
        getline(std::cin, sentence);
        if(isPali(sentence))
                std::cout<<"Is palindrome"<<std::endl;
        else
                std::cout<<"It isn't palindrome"<<std::endl;

        return 0;
}
