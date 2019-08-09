#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
int main()
{
    std::list<int> l;
    for(int i=1; i <= 1'000'000; i++)
        l.emplace_back(i);                  //real	0m0,155s
                                            //user	0m0,143s
                                            //sys	0m0,012s

   //accesing nth element in std::list using std::next()
    std::list<int>::iterator it = std::next(l.begin(),499'999);
    std::cout << "Element with index [500'000] = " << *it << std::endl;

   //2nd way to accessing nth element in std::list using std::advance()
    std::list<int>::iterator it1 = l.begin();
    std::advance(it1,499'999);
    std::cout << "Element with index [500'000] = " << *it1 << std::endl;
    

    //using access only by std::next() 
    //real	0m0,160s
    //user	0m0,140s
    //sys	0m0,020s
    
    
    //using access only by std::advance()
    //real	0m0,160s
    //user	0m0,144s
    //sys	0m0,016s

    return 0;
}
