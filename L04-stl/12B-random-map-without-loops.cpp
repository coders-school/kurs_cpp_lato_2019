#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
#include<numeric>

void print_vec(const std::vector<int> &v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}


bool is_prime(int liczba)
{
    int flag = 0;
    std::vector<int> liczby(liczba);
    std::iota(liczby.begin(), liczby.end(), 1);
    for_each(liczby.begin(), liczby.end(), [&](int x){if (liczba % x == 0) flag +=1;});

    return (flag == 2); 
}


bool is_divisor(int a, int dzielnik){return a % dzielnik == 0;}

void print_map(const std::map<int, std::vector<int>> &m)
{
    std::for_each(m.begin(), m.end(), [&](std::pair<int, std::vector<int>> m){std::cout<< m.first << ":"; print_vec(m.second);}); 
}


int main()
{
    std::vector<int> vec = {};
//    int n = 100;
//    int m = 20;
    int m,n ;
    std::cout << "Podaj granice w przedziale (0, M): \n";
    std::cin >> m;
    std::cout << "Podaj ile losowych liczb wylosowac z tego przedzialu: \n";
    std::cin >> n;


    generate_n(std::back_inserter(vec), n, [&]{return rand() % m + 1;});
    std::cout << "Random numbers: \n";
    print_vec(vec);

    // vec2 zawiera liczby pierwsze
    std::vector<int> vec2 = {};
    copy_if(vec.begin(),vec.end(),std::back_inserter(vec2), is_prime);

    // vec2 with unique elements 
    sort(vec2.begin(), vec2.end());
    auto it  = std::unique(vec2.begin(), vec2.end());
    vec2.erase(it, vec2.end());    

    std::cout << "Liczby piersze unikatowe: \n";
    print_vec(vec2);

    // mapa {{prime1: {randnum1, randnum2}},{prime1: {randnum1, randnum2}}}
    std::map<int,std::vector<int>> mapa = {};

    std::for_each(vec2.begin(),vec2.end(), [&](int prime)
    {
        std::vector<int> vec_temp = {};
        std::for_each(vec.begin(), vec.end(), [&](int randnum){
            if ((randnum % prime == 0) && std::count(vec_temp.begin(), vec_temp.end(), randnum) == 0)
            {
                vec_temp.push_back(randnum);
            }
        mapa[prime] = vec_temp;});
    });

    std::cout << "Elementy mapy new: \n";
    print_map(mapa);



    return 0;
}

