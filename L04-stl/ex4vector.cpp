#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v;

    for(int i=1; i<=1'000'000; i++)
    {
        back_inserter(v) = i;
    }

    /*
    real	0m0,042s
    user	0m0,031s
    sys	    0m0,011s
    */
                

    std::cout << "Value of [500'000] = " << v[500'000];
    /*
    real	0m0,040s
    user	0m0,032s
    sys 	0m0,008s
*/
    return 0;
}
