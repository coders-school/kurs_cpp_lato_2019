#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<unsigned int> SieveOfAtkins(unsigned int limit)
{
    vector<bool> sieve(limit, false);

    /* Mark siev[n] is true if one of the following is true:
    a) n = (4*x*x)+(y*y) has odd number of solutions
    b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
    c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */

    auto count = static_cast<size_t>(floor(sqrt(limit)));
    vector<unsigned int> range(count);
    iota(begin(range), end(range), 1);

    for_each(begin(range), end(range), [&]( unsigned int x) {
        for_each(begin(range), end(range), [&]( unsigned int y) {

            unsigned int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] = sieve[n] xor true;

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] = sieve[n] xor true;

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] = sieve[n] xor true;
        });
    });

    // Mark all multiples of squares as non-prime
    unsigned int z, r = 5;
    while(r * r < limit) {
        if (sieve[r]) {
            z = r * r;
            while (z < limit) {
                sieve[z] = false;
                z += r * r;
            }
        }
        r++;
    }

    vector<unsigned int> answer;
    if (limit > 2)
        answer.push_back(2);
    if (limit > 3)
        answer.push_back(3);
    if (limit > 4) {
        unsigned int i = 5;
        for_each(begin(sieve) + 5, end(sieve), [&](bool prime) {
            if (prime)
                answer.push_back(i);
            i++;

        });
    }

    return answer;
}
