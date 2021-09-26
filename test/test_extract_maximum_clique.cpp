// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <gtest/gtest.h>

#include "extract_maximum_clique.hpp"
#include "graph.hpp"

namespace {
using namespace extraction_of_maximum_clique;

const WeightedGraph
    T1 = {Vertices{1, 2}, Edges{{1, 2}}, ReciprocalWeights{{{1, 2}, 1}}},
    T2 = {Vertices{2, 3, 5}, Edges{{2, 3}, {2, 5}, {3, 5}},
          ReciprocalWeights{{{2, 3}, 1}, {{2, 5}, 1}, {{3, 5}, 1}}},
    T3 = {Vertices{2, 3, 5}, Edges{{2, 3}, {3, 5}},
          ReciprocalWeights{{{2, 3}, 1}, {{3, 5}, 1}}},
    T4 = {Vertices{2, 3, 5}, Edges{{2, 3}, {2, 5}, {3, 5}},
          ReciprocalWeights{{{2, 3}, 1}, {{2, 5}, 1}, {{3, 5}, 2}}},
    S1 = {Vertices{1, 2, 3, 4}, Edges{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}},
          ReciprocalWeights{
              {{1, 2}, 1}, {{1, 3}, 1}, {{1, 4}, 1}, {{2, 3}, 1}, {{3, 4}, 1}}},
    S2 = {Vertices{1, 2, 3, 4, 5, 6, 7, 8},
          Edges{{1, 2},
                {1, 3},
                {1, 4},
                {1, 5},
                {2, 3},
                {2, 4},
                {2, 5},
                {3, 4},
                {3, 5},
                {4, 5},
                {5, 6},
                {5, 7},
                {6, 7},
                {6, 8},
                {7, 8}},
          ReciprocalWeights{{{1, 2}, 1},
                            {{1, 3}, 1},
                            {{1, 4}, 1},
                            {{1, 5}, 1},
                            {{2, 3}, 1},
                            {{2, 4}, 1},
                            {{2, 5}, 1},
                            {{3, 4}, 1},
                            {{3, 5}, 1},
                            {{4, 5}, 1},
                            {{5, 6}, 1},
                            {{5, 7}, 1},
                            {{6, 7}, 1},
                            {{6, 8}, 1},
                            {{7, 8}, 1}}};
WeightedGraph S3 = S2;
bool init = []() {
    S3.e.insert({1, 6});
    S3.rw[{1, 6}] = 2;
    return true;
}();

TEST(IsCompleteGraphTest, True) {
    EXPECT_TRUE(is_complete_graph(T1));
    EXPECT_TRUE(is_complete_graph(T2));
}

TEST(IsCompleteGraphTest, False) {
    EXPECT_FALSE(is_complete_graph(T3));
    EXPECT_FALSE(is_complete_graph(T4));
}

TEST(InitializeGraphTest, xxx) {
    const auto U1 = initialize_graph(S1);
    EXPECT_EQ(S1, U1);
    const auto U2 = initialize_graph(S2);
    EXPECT_EQ(S3, U2);
}
}  // namespace
