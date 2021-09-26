// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "calculate_km.hpp"
#include "graph.hpp"

namespace {
using namespace extraction_of_maximum_clique;

const Polynomial f1 = {-1, 3, -3, 1}, g1 = {4, -5, 1},
                 f2 = {-5, 4, 0, -3, 1, 7, 6}, g2 = {5, 6, 8, -3, 5},
                 f3 = {-28, -55, 72, 13, -2}, g3 = {4, 1};
const vector<Polynomial> fs = {f1, g1, f2, g2, f3, g3};
const WeightedGraph S1 = {Vertices{1, 2}, Edges{{1, 2}},
                          ReciprocalWeights{{{1, 2}, 1}}},
                    S2 = {Vertices{2, 3, 5}, Edges{{2, 3}, {3, 5}},
                          ReciprocalWeights{{{2, 3}, 1}, {{3, 5}, 2}}};

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

TEST(GetKmTest, xxx) {
    EXPECT_EQ(1, get_km(S1));
    EXPECT_EQ(1, get_km(S2));
}

TEST(SieveOfEratosthenesTest, AtLeast2) {
    const vector<int> primes2 = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    EXPECT_EQ(vector<int>{2}, sieve_of_Eratosthenes(2));
    EXPECT_EQ(primes2, sieve_of_Eratosthenes(25));
}

TEST(GetDoubleAdjacentMatrixTest, xxx) {
    const Matrix A1 = {{0, 2}, {2, 0}};
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
    EXPECT_EQ(5, sigma(fs, 0));
    EXPECT_EQ(1, sigma(fs, -4));
}

TEST(SigmaTest, Infinity) {
    EXPECT_EQ(2, sigma(fs, Infinity::Positive));
    EXPECT_EQ(2, sigma(fs, Infinity::Negative));
}

TEST(GetNumberOfRootsByStrumTest, xxx) {
    EXPECT_EQ(0, get_number_of_roots_by_strum(f2));
    EXPECT_EQ(1, get_number_of_roots_by_strum(f3));
}

TEST(GetCoefficientTest, xxx) {
    const Polynomial h1 = {-4, 0, 1};
    const Polynomial h2 = {0, -5, 0, 1};
    EXPECT_EQ(h1, get_coefficient(S1));
    EXPECT_EQ(h2, get_coefficient(S2));
}

TEST(CalculateDeterminantTest, xxx) {
    const PolynomialMatrix A1 = {{{10, -3, 5}}};
    const PolynomialMatrix A2 = {
        {{1, -1}, {2}, {3}}, {{3}, {4, -1}, {5}}, {{3}, {5}, {9, -1}}};
    const Polynomial h1 = {10, -3, 5};
    const Polynomial h2 = {-4, -9, 14, -1};
    EXPECT_EQ(h1, calculate_determinant(A1));
    EXPECT_EQ(h2, calculate_determinant(A2));
}

TEST(PolynomialOperationTest, OperatorTimes) {
    const Polynomial h1 = {-4, 17, -28, 22, -8, 1};
    const Polynomial h2 = {-25, -10, -16, 32, -50, 37, 89, 74, 32, 17, 30};
    EXPECT_EQ(h1, f1 * g1);
    EXPECT_EQ(h2, f2 * g2);
}

TEST(PolynomialOperationTest, OperatorIntTimes) {
    const Polynomial h1 = {2, -6, 6, -2};
    EXPECT_EQ(h1, -2 * f1);
    EXPECT_EQ(Polynomial{}, 0 * f2);
}

TEST(PolynomialOperationTest, OperatorAdditionAssignment) {
    Polynomial h1 = {-1, 3}, h2 = {-5, 4, 0, -3, 1, 7, 6}, h3 = {-5, -1};
    const Polynomial k1 = {3, -2, 1}, k2 = {0, 10, 8, -6, 6, 7, 6}, k3 = {-1};
    h1 += g1;
    h2 += g2;
    h3 += g3;
    EXPECT_EQ(k1, h1);
    EXPECT_EQ(k2, h2);
    EXPECT_EQ(k3, h3);
}
}  // namespace
