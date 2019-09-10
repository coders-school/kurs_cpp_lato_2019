#include <iostream>
#include <random>
#include <map>
#include <set>
#include <algorithm>

#include "task12B.hpp"
#include "Atkins.hpp"

using namespace std;

int main() {

    if (debugMode) {
        N = 10000;
        M = 100;
    } else {
        cout << "Please input how many numbers (N) should be generated: " << endl;
        cout << ">> ";
        cin >> N;
        cout << "Please input maximum value of numbers (M) : " << endl;
        cout << ">> ";
        cin >> M;
    }

    vector<unsigned int> randomNumbers(N);

    generateRandomNumbers(randomNumbers);

    set<unsigned int> randomNumbersSorted(begin(randomNumbers), end(randomNumbers));

    vector<unsigned int> allPrimesUpToM;

    allPrimesUpToM = SieveOfAtkins(M);

    map<unsigned int, set<unsigned int>> mapping;

    for_each(begin(allPrimesUpToM), end(allPrimesUpToM), [&]( unsigned int prime)
    {
        for_each(begin(randomNumbersSorted), end(randomNumbersSorted), [&](unsigned int number) {
            if (isDivisor(number, prime)) {
                mapping[prime].insert(number);
            }
        });
    });

    return 0;
}

void generateRandomNumbers(vector<unsigned int> &randomNumbers) {
    std::generate(randomNumbers.begin(), randomNumbers.end(), getRandomNumber);
}

default_random_engine initiateRandomGenerator() {
    random_device r;
    default_random_engine e1(r());
    return e1;
}

unsigned int generateRandom(default_random_engine& e1, unsigned int upNumber) {
    uniform_int_distribution<unsigned int> uniform_dist(0, upNumber);
    return uniform_dist(e1);
}

unsigned int getRandomNumber() {
    auto engine = initiateRandomGenerator();
    return generateRandom(engine, M);
}



