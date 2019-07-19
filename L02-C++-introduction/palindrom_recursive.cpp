#include <string>
#include <string_view>
#include <iostream>
using namespace std;
bool palindrom(std::string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom(napis.substr(1, napis.size() - 2));
}

int main()
{
	cout<<palindrom("ala");
	return 0;
}
