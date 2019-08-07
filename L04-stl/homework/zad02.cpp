#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v){
    for(const auto & element : v){
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

void printVectorSize(const std::vector<int> &v){
    std::cout << "Vector size: " << v.size() << '\n';
}

void printVectorMaxSize(const std::vector<int> &v){
    std::cout << "Vector max_size: " << v.max_size() << '\n';    
}

int main(){
    std::vector<int> v1 = {1, 2, 4, 5, 6};
    std::vector<int>::iterator it = v1.begin() + 0; 
    v1.erase(it);
    v1.push_back(5);
    it = v1.begin();
    v1.emplace(it ,12);
        
    printVectorSize(v1);
    printVectorMaxSize(v1);
    printVector(v1);
    v1.clear();
    printVectorSize(v1);
    return 0;
}