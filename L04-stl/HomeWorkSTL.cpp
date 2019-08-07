#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <random>
#include <vector>

using namespace std;
void exercise1()
{
    array<int, 10> ar;                                          //create array with 10 size
    ar.fill(5);                                                 //fill all element value 5
    ar.at(4) = 3;                                               //asign 3 for 4 element
    array<int, 10> ar1 = {2, 5, 3, 9, 13, 35, 21, 0, 44, 31};   //create new array, type int size 10
    for(auto element: ar ) {cout<<element<<" ";}; cout<<endl;   //show array ar
    for(auto element: ar1) {cout<<element<<" ";}; cout<<endl;   //show array ar1
    ar.swap(ar1);                                               //replacment arrays         
    for(auto element: ar ) {cout<<element<<" ";};               //show ar after replacment
    for(auto element: ar1) {cout<<element<<" ";}; cout<<endl;   //show ar1 after replacment
};
void exercise2()
{
    vector<int> v = {1, 2, 4, 5, 6};                                          //Ceate a vector with following values { 1, 2, 4, 5, 6 }.
    v.erase(v.begin());                                                       //Erase the first value.
    v.push_back(5);                                                           //Add 5 at the end.
    v.emplace(v.begin(), 12);                                                 //create new array, type int size 10
    cout<<"Size is: "<<v.size()<<endl<<"Max_size is : "<<v.max_size()<<endl;  //Print vector size and max_size.
    for(auto element: v ) {cout<<element<<" ";}; cout<<endl;                  //Print vector
    v.clear();                                                                //Clear vector
    for(auto element: v ) {cout<<element<<" ";}; cout<<endl;                  //Print vector
};
int main()
{
    exercise1();
    exercise2();

    return 0;
}
