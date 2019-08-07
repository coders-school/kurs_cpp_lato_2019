#include <iostream>
#include <forward_list>

void populateForwardList(std::forward_list<int> &fl, unsigned count){
    auto it = fl.before_begin();
    for(unsigned i=1; i<=count; ++i){
        fl.emplace_after(it, i);
        ++it;
    }
}
        
void printForwardList(const std::forward_list<int> &fl){
    for(const auto & element : fl)
        std::cout << element << ' ';
    std::cout << '\n';
}

unsigned calculateForwardListSize(const std::forward_list<int> &fl){
    unsigned counter = 0;
    for(auto it = fl.begin(); it!=fl.end(); ++it)
        ++counter;
    return counter;
}

unsigned returnNthValueFromForwardList(const std::forward_list<int> &fl, unsigned n){
    auto it = fl.begin();
    for(unsigned i=0; i<n-1; ++i) ++it;
    return *it;
}

std::forward_list<int>::iterator returnForwardListIterator(std::forward_list<int> &fl, unsigned n){
    auto it = fl.begin();
    for(unsigned i=0; i<n-1; ++i) ++it;
    return it;
}

unsigned countDistanceBetweenIterators(const std::forward_list<int>::iterator it1, const std::forward_list<int>::iterator it2){
        unsigned counter = 0;
        for(auto it = it1; it!=it2; ++it) ++counter;
        return counter;
    }

int main(){
    std::forward_list<int> flist1;
    populateForwardList(flist1, 11);
    printForwardList(flist1);
    auto it1 = flist1.begin();
    auto it2 = flist1.end();    
    std::cout << "Forward list size is: " << countDistanceBetweenIterators(it1, it2) << '\n';    
    auto it5 = returnForwardListIterator(flist1, 5);
    std::cout << "5th element from the forward_list is: " << *it5 << '\n';
    std::cout << "Distance between begin() iterator to the 5th element iterator is: "
        << countDistanceBetweenIterators(flist1.begin(), it5) << '\n';
    // std::cout << "Forward list size: " << calculateForwardListSize(flist1) << '\n'; 
    // std::cout << "5th element from the forward_list is: " << returnNthValueFromForwardList(flist1, 5) << '\n';
    return 0;
}
