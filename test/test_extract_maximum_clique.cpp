// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "extract_maximum_clique.hpp"
#include "graph.hpp"

using namespace std;

const WeightedGraph T1 = {Vertices{1, 2}, Edges{{1, 2}},
                          ReciprocalWeights{{{1, 2}, 1}}},
                    T2 = {Vertices{2, 3, 5}, Edges{{2, 3}, {2, 5}, {3, 5}},
                          ReciprocalWeights{
                              {{2, 3}, 1}, {{2, 5}, 1}, {{3, 5}, 1}}},
                    T3 = {Vertices{2, 3, 5}, Edges{{2, 3}, {3, 5}},
                          ReciprocalWeights{{{2, 3}, 1}, {{3, 5}, 1}}},
                    T4 = {Vertices{2, 3, 5}, Edges{{2, 3}, {2, 5}, {3, 5}},
                          ReciprocalWeights{
                              {{2, 3}, 1}, {{2, 5}, 1}, {{3, 5}, 2}}};

TEST(IsCompleteGraphTest, True) {
    EXPECT_TRUE(is_complete_graph(T1));
    EXPECT_TRUE(is_complete_graph(T2));
}

TEST(IsCompleteGraphTest, False) {
    EXPECT_FALSE(is_complete_graph(T3));
    EXPECT_FALSE(is_complete_graph(T4));
}
