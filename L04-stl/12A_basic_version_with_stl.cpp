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
    
     string text ="abcdef    abcd A ";
    cout<<text;
    // int N= text.size();
    srand(time(NULL));
	int key = (rand()%10)+1;
    int charwithkey;
    
    vector<char> wektor;
      vector<char> wektor2;
    wektor.reserve(text.size()); 
    wektor2.reserve(text.size()); 
    map<int,char> myMap;
    myMap.clear();
    int it =0;
   
   for_each(text.begin(),
            text.end(),
            [  &myMap, &it, &key](char &  text)
            {
               //int it=0;
               int znak= int (text)+key;
               myMap.emplace(std::make_pair(it,text));
               it++;

            });
        it=0;
    for_each(text.begin(), text.end(), [&it,&wektor2,&myMap](char& text)
        {
                auto search=  myMap.find(it);
                if (search!=myMap.end())
                   {
                        char character = search->second;
                        wektor2.push_back(character);
                } 
                it++;
        
        });
	std::for_each(wektor2.begin(), wektor2.end(), [=](auto& el){std::cout<<el;});

    return 0;
}
