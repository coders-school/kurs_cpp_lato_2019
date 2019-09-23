#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <vector>

bool is_prime(int n) {
  // Corner cases
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }

  // This is checked so that we can check only odd values
  if (n % 2 == 0) {
    return false;
  }

  for (int i = 5; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void print_vect(const std::vector<int> &v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

void print_map(const std::map<int, std::vector<int>> &m) {
  for (auto &i : m) {
    std::cout << i.first << " => ";
    print_vect(i.second);
    std::cout << std::endl;
  }
}

int main() {
  std::cout << "How many random values would you like to generate [N]?"
            << std::endl;
  int N = 0, M = 0;

  if ((!(std::cin >> N)) || (N < 1)) {
    std::cerr << "Wrong N value!" << std::endl;
    return 1;
  }

  std::cout << "What is the maximum value to generate [M]?" << std::endl;

  if ((!(std::cin >> M)) || (M < 1)) {
    std::cerr << "Wrong M value!" << std::endl;
    return 1;
  }

  std::cout << "N = " << N << " M = " << M << std::endl;

  std::vector<int> rand_numbers;

  auto random_generator =
      [distribution_ = std::uniform_int_distribution<int>(1, M),
       random_engine_ = std::mt19937{std::random_device{}()}]() mutable {
        return distribution_(random_engine_);
      };

  std::generate_n(std::back_inserter(rand_numbers), N, random_generator);

  std::vector<int> prime_numbers;

  // Walk from 1 to M and append vector with the index number if is prime or 0
  // if is not
  std::generate_n(std::back_inserter(prime_numbers), M, [n = 1]() mutable {
    if (is_prime(n)) {
      return n++;
    } else {
      n++;
      return 0;
    }
  });

  // Remove all 'zeros' from prime numbers vector
  prime_numbers.erase(
      std::remove(prime_numbers.begin(), prime_numbers.end(), 0),
      prime_numbers.end());

  std::cout << "Rand numbers:" << std::endl;
  print_vect(rand_numbers);
  std::cout << std::endl;
  std::cout << "Prime numbers:" << std::endl;
  print_vect(prime_numbers);
  std::cout << std::endl;

  std::map<int, std::vector<int>> divisor_map;

  for (auto &r : rand_numbers) {
    std::vector<int> divisors;

    for (auto &p : prime_numbers) {
      if (!(r % p)) {
        divisors.emplace_back(p);
      }
    }
    divisor_map.emplace(r, divisors);
  }

  std::cout << "Divisor map: " << std::endl;

  print_map(divisor_map);

  return 0;
}
