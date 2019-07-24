#include <iostream>
#include <string_view>

using namespace std;

bool palindrom(string_view napis) {
  if (napis.size() < 2)
    return true;

  return napis.front() == napis.back() &&
         palindrom(napis.substr(1, napis.size() - 2));
}

int main() {

  string longString(300000, 'Z');
  cout << boolalpha << palindrom("manam") << endl;
  cout << boolalpha << palindrom("gggggggggggg") << endl;
  cout << boolalpha << palindrom("marcin") << endl;
  cout << boolalpha << palindrom(longString) << endl;

  return 0;
}