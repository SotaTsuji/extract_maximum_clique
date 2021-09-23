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
    EXPECT_EQ(primes1_cmp, primes1);
    EXPECT_EQ(primes2_cmp, primes2);
}

TEST(GetPrimeListTest, Inputs) {
    const auto prime_list1 = get_prime_list(2, 500);
    const vector<int> prime_list1_cmp = {13, 11, 7};
    const auto prime_list2 = get_prime_list(5, 10'000'000);
    const vector<int> prime_list2_cmp = {97, 89, 83, 79};
    EXPECT_EQ(prime_list1_cmp, prime_list1);
    EXPECT_EQ(prime_list2_cmp, prime_list2);
}
