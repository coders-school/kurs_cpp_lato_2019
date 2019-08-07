#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<time.h>
#include<iterator>

void print_list(const std::list<int> &l)
{
    transform(l.begin(),l.end(),std::ostream_iterator<int>(std::cout, " "), [](const auto &a){return a;});
    std::cout << std::endl;
}

void print_vec(const std::vector<int> &v)
{
    copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;
}


int main()
{
    std::list<int> lista = {};
    static int a = 1;
    generate_n(back_inserter(lista), 1000000, []{return a++;});

    unsigned t0, t1, t2, t3;
    t0 = clock();
    print_list(lista);
    t1 = clock() - t0;
    
    std::list<int>::iterator it = lista.begin();
    
    t0 = clock();
    std::advance(it, 499999);
    std::cout << "Value of lista[500000] is : " << *it << std::endl;
    t2 = clock() - t0;
    
    std::vector<int> vec(lista.size());
    copy(lista.begin(),lista.end(),vec.begin());

    t0 = clock();
    print_vec(vec);
    t3 = clock() - t0;

    std::cout << "Times [ms] to: print list, retrieve value at index, print vector: " << t1 << " " << t2 << " " << t3 << std::endl;

    return 0;
}

    // print lista  =>  time a.out: real   0m0.552s, user    0m0.382s, sys 0m0.056s
    // index lista  =>  time a.out: real   0m0.236s, user    0m0.211s, sys 0m0.019s
    // print vector =>  time a.out: real   0m0.615s, user    0m0.402s, sys 0m0.065s   
