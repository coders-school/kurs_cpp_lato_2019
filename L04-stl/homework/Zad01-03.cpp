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
void exercise3()
{
    vector<int> v;                                                            //Ceate empty vector
    cout<<"Size is: "<<v.size()<<" Capacity is : "<<v.capacity()<<endl;  //Print vector size and capacity
    v.resize(10,5);                                                           //Resize vector to size 10 and fill it with 5.
    cout<<"Size is: "<<v.size()<<" Capacity is : "<<v.capacity()<<endl;  //Print vector size and capacity
    v.resize(20);                                                             //Resize vector to size 10 and fill it with 5.
    cout<<"Size is: "<<v.size()<<" Capacity is : "<<v.capacity()<<endl;  //Print vector size and capacity
    v.shrink_to_fit();                                                        //Shrink_to_fit
    cout<<"Size is: "<<v.size()<<" Capacity is : "<<v.capacity()<<endl;  //Print vector size and capacity
};
void exercise4()
{
    //Lista
  list <int> lista;
   for(size_t i = 1; i < 1'000'001; i++) lista.push_back(i);

    //Vector
  vector <int> vector1;
  for(size_t i = 1; i < 1'000'001; i++) vector1.push_back(i);

/*
Czas wypelnienia listy:                                                          
real    0m0.096s
user    0m0.086s
sys     0m0.010s
Czas wypelnienia vectora:                             
real    0m0.093s
user    0m0.078s
sys     0m0.015s
*/
 int counter = 0;
    for(int value : lista) {
        if(counter == 500'000) cout << value << endl;
        counter++;
    };
cout<<vector1[500000]<<endl;
/*
Czas wykonania programu(lista):
real    0m0.094s
user    0m0.078s
sys     0m0.016s
Czas wykonania programu(vector):
real    0m0.095s
user    0m0.086s
sys     0m0.009s
Przy wykonywanych probach zostały wykomentowane wcześniejsze zadania*/
};
void exercise5()
{
    map<int, string> map1;                                         //Create a map of integers to strings with content:
    map1 = { {1,"One"},{2,"Two"},{3,"Thr"},{4,"Four"},{5,"Five"}}; //{1 → ‘one’, 2 → ‘two’, 3 → ‘thr’, 4 → ‘four’, 5 → ‘five’}
    map1.insert({3, "Three"});                                     //Add a new pair: 3 → ‘three’
    map1.erase(5);                                                 //Erase element with key 5
    cout<<map1.size();                                             //Print how many values exist for all keys
    auto it = map1.find(4);
    cout<<"Key "<<it->first<<" Value :"<<it->second<<endl;         //Find element with key 4 and print its key and value.
};
int main()
{
    //exercise1();
    //exercise2();
    //exercise3();
    //exercise4();
    exercise5();
    return 0;
}
