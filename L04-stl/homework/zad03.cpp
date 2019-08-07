#include <iostream>
#include <vector>

// kod do skasowania przerobienia ponizej

void printVector(const std::vector<int> &v){
    for(const auto & element : v){
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

void printVectorSize(const std::vector<int> &v){
    std::cout << "Vector size: " << v.size() << '\n';
}

void printVectorCapacity(const std::vector<int> &v){
    std::cout << "Vector capacity: " << v.capacity() << '\n';
}

void printVectorMaxSize(const std::vector<int> &v){
    std::cout << "Vector max_size: " << v.max_size() << '\n';    
}

void printVectorInfo(const std::vector<int> &v){
    printVector(v);
    printVectorSize(v);
    printVectorCapacity(v);
}

int main(){
    std::vector<int> vector1;
    printVectorInfo(vector1);
    vector1.resize(10, 5);
    printVectorInfo(vector1);
    vector1.reserve(20);
    printVectorInfo(vector1);
    vector1.shrink_to_fit();
    printVectorInfo(vector1);
    return 0;
}