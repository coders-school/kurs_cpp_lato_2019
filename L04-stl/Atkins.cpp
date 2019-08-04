#include <vector>
#include <iostream>

using namespace std;

vector<unsigned int> SieveOfAtkin(unsigned int limit)
{
   vector<unsigned int> answer;
    // 2 and 3 are known to be prime
    if (limit > 2)
        answer.push_back(2);
    if (limit > 3)
        answer.push_back(3);

    // Initialise the sieve array with false values
    vector<bool> sieve(limit, false);

    /* Mark siev[n] is true if one
       of the following is true:
    a) n = (4*x*x)+(y*y) has odd number of
       solutions, i.e., there exist
       odd number of distinct pairs (x, y)
       that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
    b) n = (3*x*x)+(y*y) has odd number of
       solutions and n % 12 = 7
    c) n = (3*x*x)-(y*y) has odd number of
       solutions, x > y and n % 12 = 11 */

    for (unsigned int x = 1; x * x < limit; x++) {
        for (unsigned int y = 1; y * y < limit; y++) {

            unsigned int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] = sieve[n] xor true;

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] = sieve[n] xor true;

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] = sieve[n] xor true;
        }
    }

    // Mark all multiples of squares as non-prime
    for (unsigned int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (unsigned int i = r * r; i < limit; i += r * r)
                sieve[i] = false;
        }
    }

    // Print primes using sieve[]
    for (unsigned int a = 5; a < limit; a++)
        if (sieve[a])
            answer.push_back(a);

    return answer;
}
