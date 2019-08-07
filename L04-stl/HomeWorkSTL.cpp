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
int main()
{
    exercise1();

    return 0;
}
