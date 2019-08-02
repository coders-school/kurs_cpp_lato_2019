#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <forward_list>
#include <functional>
#include <algorithm>
#include <numeric>
#include <functional>


void print_ar (std::array<double,6>ar)
{
    for (auto itr:ar)
        std::cout<<itr;
    std::cout<<std::endl;

}
void print_vec (std::vector<int>vec)
{
    for (auto itr:vec)
        std::cout<<itr;
    std::cout<<std::endl;
}

struct by_abs
{
    bool operator ()(double l, double r)
    {
    return std::abs(l)<std::abs(r);
    }
};


//struct Multiply_value{
//    int arg,second;
//    int multiply()
//    {
//    return std::multiplie<int>();
//    }
//};
int main () {
    //Exercise_1
    /*
    const int array_size {10};
    std::array <int,array_size> ar{};
    ar.fill(5);
    ar.at(3)=3;
    std::array <int,array_size> ar_2{};
    std::swap(ar,ar_2);
    print_ar(ar);
    print_ar(ar_2);
    */
    //Exercise_2
    /*
    std::vector <int> vec {1,2,4,5,6};
    vec.erase(vec.begin());
    vec.push_back(5);
    vec.emplace(vec.begin(),12);
    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.max_size()<<std::endl;
    print_vec(vec);
    vec.clear();
    std::cout<<vec.size()<<std::endl;
    */
    //Exercise_3
    /*
    std::vector <int> vec{};
    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.capacity()<<std::endl;
    vec.resize(10,5);
    print_vec(vec);
    vec.reserve(20);
    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.capacity()<<std::endl;
    vec.shrink_to_fit();
    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.capacity()<<std::endl;
    */
    //Exercise_4
    std::cout<<"===========Exercise 4==========="<<std::endl;
    std::list <int> l{};
    l.resize(1000000);
    std::iota(l.begin(),l.end(),1);
    std::list<int>::iterator itr=l.begin();
    std::advance(itr,500000);
    std::cout<<*itr<<std::endl;
    std::vector<int> vec{};
    vec.resize(1000000);
    std::iota(vec.begin(),vec.end(),1);
    std::cout<<vec.at(500000)<<std::endl;
    //for (long int itr=1;itr=1000;itr++)
    // l.push_back(itr); //very_long
    // vec.push_back(itr);

    //Exercise_5
    /*
    std::map<int,std::string>mapa;
    mapa[1]="one"; mapa[2]="two"; mapa[3]="thr"; mapa[4]="four"; mapa[5]="five";
    mapa[3]="three";
    mapa.erase(5);
    for (auto element:mapa)
        std::cout<<element.first<<" "<<element.second<<"\n";
    auto itr = mapa.find(4);
    std::cout<<"Key "<< itr->first<<" value "<<itr->second<<std::endl;
    */
    //Exercise_6

    std::cout<<"===========Exercise 6==========="<<std::endl;
    std::forward_list<int> numbers{1,2,3,4,16,6,7,15};
    std::forward_list<int>::iterator itr_l=std::begin(numbers);
    std::forward_list<int>::iterator itr_r=std::end(numbers);
    auto size{0};

    for (auto itr_l:numbers)
        ++size;
    std::cout<<size<<std::endl;
    std::advance(itr_l,4);
    std::cout<<*itr_l<<std::endl;
    std::cout<<std::distance(numbers.begin(),itr_l)<<std::endl;

    //Exercise_7
    /*
    int x = 11;
    std::bind(std::multiplies<int>(),5);
    */
    //Exercise_8
    /*
    std::array<double,6> data={5.0,4.0,-1.4,7.9,8.22,0.4};
    // std::sort(data.begin(),data.end(),by_abs{});
    //    lub
    std::sort(data.begin(),data.end(), [](double r, double l)
    {
    return std::abs(r)<std::abs(l);
    });
    print_ar(data);
    */
    return 0;

}
