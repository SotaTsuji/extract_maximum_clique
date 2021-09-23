// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#pragma once

#include <vector>

#include "graph.hpp"
using namespace std;

using Matrix = vector<vector<int>>;
using Polynomial = vector<int>;

// int get_maximum_coefficient(const int n);
vector<int> get_prime_list(const int n, const int c);
// Polynomial get_coefficient(const WeightedGraph& S);
// tuple<Polynomial, Polynomial, int> polynomial_division(const Polynomial& f,
//                                                        const Polynomial& g);
// int get_number_of_roots(Polynomial f);
// int get_km(const WeightedGraph& S);

vector<int> sieve_of_Eratosthenes(const int k);
// Matrix get_double_adjacent_matrix(const WeightedGraph& S);
// Polynomial get_coefficient_by_modulo(const WeightedGraph& S, const int p);
// Polynomial merge_coefficients(const Polynomial& f, const Polynomial& g);
// Polynomial differential(const Polynomial& f);
// int get_number_of_roots_by_strum(const Polynomial& f);
