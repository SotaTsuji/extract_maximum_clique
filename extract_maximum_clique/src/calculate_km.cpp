// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/calculate_km.hpp"

#include <numeric>
#include <vector>

#include "../include/graph.hpp"
using namespace std;

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
