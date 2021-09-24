// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "calculate_km.hpp"
#include "graph.hpp"

using namespace std;

TEST(GetMaximumCoefficient, AtLeast2) {
    EXPECT_EQ(4, get_maximum_coefficient(2));
    EXPECT_EQ(29'568'000'000, get_maximum_coefficient(11));
}

TEST(GetPrimeListTest, xxx) {
    const vector<int> prime_list1 = {13, 11, 7};
    const vector<int> prime_list2 = {97, 89, 83, 79, 73, 71};
    EXPECT_EQ(prime_list1, get_prime_list(2, 500));
    EXPECT_EQ(prime_list2, get_prime_list(5, 100'000'000'000));
}

TEST(PolynomialDivisionTest, xxx) {
    Polynomial f1 = {-1, 3, -3, 1};
    Polynomial g1 = {4, -5, 1};
    Polynomial f2 = {-5, 4, 0, -3, 1, 7, 6};
    Polynomial g2 = {5, 6, 8, -3, 5};
    tuple<Polynomial, Polynomial, Bint> output1 = {{2, 1}, {-9, 9}, 1};
    tuple<Polynomial, Polynomial, Bint> output2 = {
        {-56, 265, 150}, {-345, -489, -1892, -3563}, 125};
    EXPECT_EQ(output1, polynomial_division(f1, g1));
    EXPECT_EQ(output2, polynomial_division(f2, g2));
}

TEST(SieveOfEratosthenesTest, AtLeast2) {
    const vector<int> primes1 = {2};
    const vector<int> primes2 = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    EXPECT_EQ(primes1, sieve_of_Eratosthenes(2));
    EXPECT_EQ(primes2, sieve_of_Eratosthenes(25));
}

TEST(GetDoubleAdjacentMatrixTest, xxx) {
    WeightedGraph S1, S2;
    S1.v = {1, 2};
    S1.e = {{1, 2}};
    S1.rw[{1, 2}] = 1;
    const Matrix A1 = {{0, 2}, {2, 0}};
    S2.v = {2, 3, 5};
    S2.e = {{2, 3}, {3, 5}};
    S2.rw[{2, 3}] = 1;
    S2.rw[{3, 5}] = 2;
    const Matrix A2 = {{0, 2, 0}, {2, 0, 1}, {0, 1, 0}};
    EXPECT_EQ(A1, get_double_adjacent_matrix(S1));
    EXPECT_EQ(A2, get_double_adjacent_matrix(S2));
}

TEST(DifferentialTest, xxx) {
    const Polynomial f = {2};
    const Polynomial f_;
    const Polynomial g = {2, -4, 7, 4, 1};
    const Polynomial g_ = {-4, 14, 12, 4};
    EXPECT_EQ(f_, differential(f));
    EXPECT_EQ(g_, differential(g));
}
