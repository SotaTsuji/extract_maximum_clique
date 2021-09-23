// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "calculate_km.hpp"
#include "graph.hpp"

using namespace std;

TEST(SieveOfEratosthenesTest, AtLeast2) {
    const auto primes1 = sieve_of_Eratosthenes(2);
    const auto primes2 = sieve_of_Eratosthenes(25);
    const vector<int> primes1_cmp = {2};
    const vector<int> primes2_cmp = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    EXPECT_EQ(primes1_cmp.size(), primes1.size());
    for (auto i = 0; i < primes1.size(); ++i) {
        EXPECT_EQ(primes1_cmp[i], primes1[i]);
    }
    EXPECT_EQ(primes2_cmp.size(), primes2.size());
    for (auto i = 0; i < primes2.size(); ++i) {
        EXPECT_EQ(primes2_cmp[i], primes2[i]);
    }
}
