#include <string>
#include <string_view>
#include <iostream>
bool palindrom(std::string_view sv)
{	
    if(sv.size() < 2) return true;

    return sv.front() == sv.back()
        && palindrom(sv.substr(1, sv.size() - 2));
}

int main()
{
	std::string napis;
	std::cout<<"Write word to check. ";
        std::cin>>napis;

	if(palindrom(napis))
		std::cout<<"It's palindrome. \n";

	else
		std::cout<<"It isn't palindrome. \n";
}
