#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>

void print_vec(const std::vector<int> &v)
{
    for (auto i: v){std::cout << i << " ";}
    std::cout << std::endl;
}

bool is_prime(int liczba)
{
    int flag = 0;
    for (int i = 1; i <= liczba; ++i) {if (liczba % i == 0) flag += 1;}
    return (flag == 2); 
}

std::vector<int> divisors(int number)
{
    std::vector<int> vd = {};
    for (int i = 1; i <= number; ++i){if (number % i == 0){vd.push_back(i);}}
    return vd;
}


bool is_divisor(int a, int dzielnik)
{
    return a % dzielnik == 0;   
}


int main()
{
    std::vector<int> vec = {};
    int n = 100;
    int m = 20;
//    std::cout << "Podaj granice w przedziale (0, M): \n";
//    std::cin >> m;
//    std::cout << "Podaj ile losowych liczb wylosowac z tego przedzialu: \n";
//    std::cin >> n;


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

    for (int prime: vec2)
    {
        std::vector<int> vec_temp = {};
        for (int randnum: vec)
            if ((randnum % prime == 0) && std::count(vec_temp.begin(), vec_temp.end(), randnum) == 0)
            {
                vec_temp.push_back(randnum);
            }
        mapa[prime] = vec_temp;
    }

    std::cout << "Elementy mapy: \n";
    for (auto & el : mapa)
    {
        std::cout << el.first << ": ";
        print_vec(el.second);
    }




//    copy(mapa.begin(),mapa.end(),std::ostream_iterator<int>(std::cout, ","));    

    return 0;
}

