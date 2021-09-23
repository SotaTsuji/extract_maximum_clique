// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "extract_maximum_clique.hpp"
#include "graph.hpp"

using namespace std;

TEST(IsCompleteGraphTest, True) {
    WeightedGraph T1, T2;
    T1.v = {1, 2};
    T1.e = {{1, 2}};
    T1.rw[{1, 2}] = 1;
    T2.v = {2, 3, 5};
    T2.e = {{2, 3}, {2, 5}, {3, 5}};
    T2.rw[{2, 3}] = T2.rw[{2, 5}] = T2.rw[{3, 5}] = 1;
    EXPECT_TRUE(is_complete_graph(T1));
    EXPECT_TRUE(is_complete_graph(T2));
}

TEST(IsCompleteGraphTest, False) {
    WeightedGraph T3, T4;
    T3.v = {2, 3, 5};
    T3.e = {{2, 3}, {2, 5}};
    T3.rw[{2, 3}] = T3.rw[{2, 5}] = 1;
    T4.v = {2, 3, 5};
    T4.e = {{2, 3}, {2, 5}, {3, 5}};
    T4.rw[{2, 3}] = T4.rw[{2, 5}] = 1;
    T4.rw[{3, 5}] = 2;
    EXPECT_FALSE(is_complete_graph(T3));
    EXPECT_FALSE(is_complete_graph(T4));
}
