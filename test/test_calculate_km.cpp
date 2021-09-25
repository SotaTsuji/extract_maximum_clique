// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "calculate_km.hpp"
#include "graph.hpp"

using namespace std;

const Polynomial f1 = {-1, 3, -3, 1}, g1 = {4, -5, 1},
                 f2 = {-5, 4, 0, -3, 1, 7, 6}, g2 = {5, 6, 8, -3, 5},
                 f3 = {-28, -55, 72, 13, -2}, g3 = {4, 1};

TEST(PolynomialOperationTest, UnaryOperatorMinus) {
    const Polynomial h1 = {1, -3, 3, -1};
    const Polynomial h2 = {5, -4, 0, 3, -1, -7, -6};
    EXPECT_EQ(h1, -f1);
    EXPECT_EQ(h2, -f2);
}

TEST(PolynomialOperationTest, OperatorDivision) {
    const Polynomial h1 = {2, 1};
    const Polynomial h2 = {-56, 265, 150};
    const Polynomial h3 = {-7, -12, 21, -2};
    EXPECT_EQ(h1, f1 / g1);
    EXPECT_EQ(h2, f2 / g2);
    EXPECT_EQ(h3, f3 / g3);
}

TEST(PolynomialOperationTest, OperatorDivisionBint) {
    const Polynomial f = {-28, -14, 98, 49, -21};
    const Polynomial h = {4, 2, -14, -7, 3};
    EXPECT_EQ(f1, f1 / 1);
    EXPECT_EQ(h, f / -7);
}

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
    const tuple<Polynomial, Polynomial, Bint> output1 = {{2, 1}, {-9, 9}, 1};
    const tuple<Polynomial, Polynomial, Bint> output2 = {
        {-56, 265, 150}, {-345, -489, -1892, -3563}, 125};
    EXPECT_EQ(output1, polynomial_division(f1, g1));
    EXPECT_EQ(output2, polynomial_division(f2, g2));
}

TEST(GetNumberOfRootsTest, xxx) {
    const Polynomial f = {-24, -8, -6, 4, 20, 12, 2};
    EXPECT_EQ(0, get_number_of_roots(f1));
    EXPECT_EQ(3, get_number_of_roots(f));
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
    S1.rw = {{{1, 2}, 1}};
    const Matrix A1 = {{0, 2}, {2, 0}};
    S2.v = {2, 3, 5};
    S2.e = {{2, 3}, {3, 5}};
    S2.rw = {{{2, 3}, 1}, {{3, 5}, 2}};
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

TEST(PolynomialOperationTest, SimplifyCoefficient) {
    const Polynomial h3 = {28, 55, -72, -13, 2};
    const Polynomial f = {3, -9, 0, -6, 15};
    const Polynomial h = {1, -3, 0, -2, 5};
    EXPECT_EQ(h3, simplify_coefficient(f3));
    EXPECT_EQ(h, simplify_coefficient(f));
}

TEST(PolynomialOperationTest, Gcd) {
    const Polynomial h1 = {-1, 1};
    EXPECT_EQ(h1, gcd(f1, g1));
    EXPECT_EQ(Polynomial(1, 1), gcd(f2, g2));
}

TEST(PolynomialOperationTest, Rem) {
    const Polynomial h1 = {-9, 9};
    const Polynomial h2 = {-345, -489, -1892, -3563};
    EXPECT_EQ(h1, rem(f1, g1));
    EXPECT_EQ(h2, rem(f2, g2));
}

TEST(SubstituteIntoPolynomialTest, xxx) {
    EXPECT_EQ(-1, substitute_into_polynomial(f1, 0));
    EXPECT_EQ(115890, substitute_into_polynomial(f2, 5));
}

TEST(SigmaTest, RealNumber) {
    vector<Polynomial> fs = {f1, g1, f2, g2, f3, g3};
    EXPECT_EQ(5, sigma(fs, 0));
    EXPECT_EQ(1, sigma(fs, -4));
}

TEST(SigmaTest, Infinity) {
    vector<Polynomial> fs = {f1, g1, f2, g2, f3, g3};
    EXPECT_EQ(2, sigma(fs, Infinity::Positive));
    EXPECT_EQ(2, sigma(fs, Infinity::Negative));
}

TEST(GetNumberOfRootsByStrumTest, xxx) {
    EXPECT_EQ(0, get_number_of_roots_by_strum(f2));
    EXPECT_EQ(1, get_number_of_roots_by_strum(f3));
}
