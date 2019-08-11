#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

const int ASCII_size = 128;

/*
std::pair<char, char> generate_cipher()
{
    
    static int i = 0;
    i++;

    char left = static_cast<char>(i);
    char right = static_cast<char>((i + rand()) % ASCII_size);

    //auto p =  make_pair(left, right);
    return std::pair<char, char>(left, right);

}
*/


void create_cipher_map(map<char, char> & cipher_map)
{
    unsigned int random_value = rand();
    //generate_n(cipher_map.begin(), ASCII_size, generate_cipher);
    for(int i = 0; i < ASCII_size; i++) {
        cipher_map.insert(pair<char, char>(i, (i + random_value) % ASCII_size));
    }
    /*
    for(auto el: cipher_map) {
        cout << el.first << " " << el.second << ", ";
    } cout << endl;
    */
    
    
}

void encrypt(const map<char, char> & cipher_map, const string & input, string & output)
{
    for(unsigned int i = 0; i < input.size(); i++) {
        output.push_back(cipher_map.at(input[i]));
    }
    /*
    for(auto el: output) {
        cout << el << ", ";
    } cout << endl;
    */
}

void decrypt(const map<char, char> & cipher_map, const string & input, string & output)
{
    char value;

    for(unsigned int i = 0; i < input.size(); i++) {
        value = static_cast<char>(input[i]);
         
        auto element_of_cipher_map = std::find_if(
          cipher_map.begin(),
          cipher_map.end(),
          [value](const auto& cm) {return cm.second == value; });

        if(element_of_cipher_map != cipher_map.end()) {
            output.push_back(element_of_cipher_map->first);
        }
    }    
}


int main()
{
    srand (time(NULL));  

    map<char, char> cipher_map;

    create_cipher_map(cipher_map);

    string s = "alicja";
    cout << s << endl;

    string encrypted_s;
    encrypt(cipher_map, s, encrypted_s);

    cout << encrypted_s << endl;

    string decrypted_s;
    decrypt(cipher_map, encrypted_s, decrypted_s);

    cout << decrypted_s << endl;


    return 0;
}

