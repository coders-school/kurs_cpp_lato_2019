#include <string_view>
#include <iostream>


std::string_view name_sv;

bool palindrom(auto name_sv)
{
    if(name_sv.size() < 2) return true;

    return name_sv.front() == name_sv.back()
        && palindrom(name_sv.substr(1, name_sv.size() - 2));
}

int main()
{
	name_sv = "kajak";
	std::cout << palindrom(name_sv) << std::endl;
}

