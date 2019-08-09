#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_palindrome(const string & str)
{
	auto it = mismatch(begin(str), end(str), rbegin(str), rend(str));
	return it.first == end(str);
}

int main()
{
	cout<<is_palindrome("kajak")<<endl;
return 0;
}