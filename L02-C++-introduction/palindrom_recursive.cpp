#include <iostream>
#include <string>
#include <string_view>

bool palindrom(std::string_view checkedWord)
{
    if(checkedWord.size() < 2) return true;

    return checkedWord.front() == checkedWord.back()
        && palindrom(checkedWord.substr(1, checkedWord.size() - 2));
}

int main()
{
	std::string word {"kajak"};

	std::cout << "Is \"" << word << "\" a palindrome? " 
		<< std::boolalpha << palindrom({word.c_str(), word.size()}) << "\n";

	return 0;
}