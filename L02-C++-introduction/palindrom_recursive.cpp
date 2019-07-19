#include <iostream>
#include <string>
#include <string_view>

bool palindrom(std::string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom(napis.substr(1, napis.size() - 2));
}

int main (){

	std::string_view word_sentence;
        //std::cout << "Give me word or sentence: \n";
        //std::getline(std::cin, word_sentence);
        word_sentence = "madam";

        if ( palindrom(word_sentence) )
	{
                std::cout<<"It is palindrome.\n";
        }
        else
	{
                std::cout<<"It isn't palindrome.\n";
        }

        return 0;
}

