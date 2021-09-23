// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/calculate_km.hpp"

#include <numeric>
#include <vector>

#include "../include/graph.hpp"
using namespace std;

// Algorithm 9
vector<int> get_prime_list(const int n, const int c) {
    auto primes = sieve_of_Eratosthenes(4 * n * n - 1);
    int s = 1;
    vector<int> prime_list;
    for (auto i = primes.size() - 1; i >= 0; --i) {
        int p_i = primes[i];
        s *= p_i;
        prime_list.push_back(p_i);
        if (s > 2 * c) {
            break;
        }
    }
    return prime_list;
}

vector<int> sieve_of_Eratosthenes(const int k) {
    vector<int> primes(k - 1);
    iota(primes.begin(), primes.end(), 2);
    for (auto i = 0;; ++i) {
        auto itr = primes.begin() + i;
        if ((*itr) * (*itr) > k) {
            break;
        }
        const int divisor = *itr;
        ++itr;
        while (itr != primes.end()) {
            if ((*itr) % divisor == 0) {
                itr = primes.erase(itr);
            } else {
                ++itr;
            }
        }
    }
    return primes;
}
