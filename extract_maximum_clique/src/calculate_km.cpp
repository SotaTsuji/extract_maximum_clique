// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/calculate_km.hpp"

#include <numeric>
#include <vector>

#include "../include/graph.hpp"
using namespace std;

// Algorithm 8
Bint get_maximum_coefficient(const int n) {
    int r = (n + 1) / 2;
    int lambda_max = 2 * (n - 1);
    Bint c_n = 1;
    Bint c_d = 1;
    Bint s = 1;
    for (auto i = 1; i <= r; ++i) {
        c_n *= (n - i + 1);
        c_d *= i;
        s *= lambda_max;
    }
    return s * c_n / c_d;
}

// Algorithm 9
vector<int> get_prime_list(const int n, const Bint c) {
    auto primes = sieve_of_Eratosthenes(4 * n * n - 1);
    Bint s = 1;
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

Matrix get_double_adjacent_matrix(const WeightedGraph& S) {
    auto n = S.v.size();
    Matrix A(n, vector<int>(n));
    for (auto i = 0; i < n - 1; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            if (S.e.contains({S.v[i], S.v[j]})) {
                A[i][j] = A[j][i] = 2 / S.rw.at({S.v[i], S.v[j]});
            }
        }
    }
    return A;
}

Polynomial differential(const Polynomial& f) {
    Polynomial f_;
    for (auto i = 1; i < f.size(); ++i) {
        f_.push_back(f[i] * i);
    }
    return f_;
}
