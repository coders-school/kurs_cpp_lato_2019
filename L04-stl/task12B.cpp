#include <iostream>
#include <random>
#include <map>
#include <set>

#include "task12B.hpp"
#include "Atkins.hpp"

using namespace std;

int main() {

    if (debugMode) {
        N = 10000;
        M = 100;
    } else {
    for (auto const & ch:SieveOfAtkin(1000))
        cout << ch << " ";
    cout << "Please input how many numbers (N) should be generated: " << endl;
    cout << ">> ";
    cin >> N;
    cout << "Please input maximum value of numbers (M) : " << endl;
    cout << ">> ";
    cin >> M;
    }

    vector<unsigned int> randomNumbers;
    randomNumbers.reserve(N);

    generateRandomNumbers(randomNumbers);

    set<unsigned int> randomNumbersSorted(randomNumbers.begin(), randomNumbers.end());

    vector<unsigned int> allPrimesUpToM;

    allPrimesUpToM = SieveOfAtkin(M);

    map<unsigned int, set<unsigned int>> mapping;

    for (auto const& prime : allPrimesUpToM) {
        for (auto const& number: randomNumbersSorted) {
            if (isDivisor(number, prime)) {
                mapping[prime].insert(number);
            }
        }

    }

    return 0;
}

void generateRandomNumbers(vector<unsigned int> &randomNumbers) {
    auto engine = initiateRandomGenerator();

    for (unsigned int i = 0; i < N; i++ ) {
        randomNumbers.push_back( generateRandom(engine, M));
    }
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



