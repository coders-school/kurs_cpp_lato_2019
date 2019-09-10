//1. Generate N random values (int numbers from 0 to M)
//2. Generate all prime numbers from 0 to M
//3. Create a map Prime -> Values, where Prime is a divisor of Value. (eg. 3 -> [6,9] where 6,9 are generated random numbers)
//4. Input data: N, M (from cin)

using namespace std;

bool debugMode = true;

unsigned int M, N;

default_random_engine initiateRandomGenerator();

unsigned int generateRandom(default_random_engine&, unsigned int);

unsigned int getRandomNumber();

void generateRandomNumbers(vector<unsigned int> &randomNumbers);

auto isDivisor = [](unsigned int number,unsigned int divisor){ return number % divisor == 0; };