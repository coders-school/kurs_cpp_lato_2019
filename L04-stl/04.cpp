#include <list>
#include <iostream>
#include <vector>
#include <numeric>

int main(){

    std::list<int> ls;
    ls.resize(1000000);
    std::iota(ls.begin(), ls.end(), 1);
    auto itHalf = std::next(ls.begin(), 500000);
    std::cout << *itHalf << '\n';

    std::vector<int> v;
    v.resize(1000000);
    std::iota(v.begin(), v.end(), 1);
    std::cout << v[500000] << '\n';

    return 0;
}
//Results: first with commented list, working vector
//second with commented vector, working list
//vectror:
//real	0m0,368s
//user	0m0,312s
//sys	0m0,023s
//list:
//real	0m0,390s
//user	0m0,312s
//sys	0m0,037s
