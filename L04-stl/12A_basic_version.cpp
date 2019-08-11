#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    cout<<endl<<endl<<endl;
     string text ="abcdef";
    // int N= text.size();
    srand(time(NULL));
    int key = (rand()%10)+1;
    cout<<key<<endl;
    int charwithkey;
    vector<char> wektor;
    wektor.reserve(text.size()); 
    map<int,char> myMap;
    myMap.clear();

    for(auto it = 0;it<=text.size(); it++)
    {
        charwithkey=int (text[it]) + key;
        char newchar = char (charwithkey);
           myMap.emplace(std::pair<int,char>(it, newchar));
    };
    for(auto it = 0;it<=text.size();it++)
    {
       auto search=  myMap.find(it);
        if (search!=myMap.end())
        {
            char character = search->second;
            wektor.push_back(character);
        } 
    }
    for (auto el:wektor )
    {
        cout<<el;
    }
    for(auto el:wektor)
    {
        int num= int (el)-key;
        cout<< char(num);

    }


    return 0;
}