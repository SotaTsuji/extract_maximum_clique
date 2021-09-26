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
                            {{7, 8}, 1}}},
    S3 = {Vertices{1, 2, 3, 4, 5, 6},
          Edges{
              {1, 2},
              {1, 5},
              {1, 6},
              {2, 3},
              {3, 4},
              {4, 5},
              {5, 6},
          },
          ReciprocalWeights{{{1, 2}, 1},
                            {{1, 5}, 1},
                            {{1, 6}, 1},
                            {{2, 3}, 1},
                            {{3, 4}, 1},
                            {{4, 5}, 1},
                            {{5, 6}, 1}}};
WeightedGraph S4;
bool init = []() {
    S4 = S2;
    S4.e.insert({1, 6});
    S4.rw[{1, 6}] = 2;
    return true;
}();

TEST(VerticesOperationTest, OperatorAdditionAssignmentVertex) {
    Vertices V = {2, 4, 5, 7, 8, 9};
    const Vertices v1 = {2, 3, 4, 5, 7, 8, 9}, v2 = {2, 3, 4, 5, 7, 8, 9, 11};
    V += 3;
    EXPECT_EQ(v1, V);
    V += 11;
    EXPECT_EQ(v2, V);
}

TEST(IsCompleteGraphTest, True) {
    EXPECT_TRUE(is_complete_graph(T1));
    EXPECT_TRUE(is_complete_graph(T2));
}

TEST(IsCompleteGraphTest, False) {
    EXPECT_FALSE(is_complete_graph(T3));
    EXPECT_FALSE(is_complete_graph(T4));
}

TEST(InitializeGraphTest, xxx) {
    const auto S1_ = initialize_graph(S1);
    EXPECT_EQ(S1, S1_);
    const auto S2_ = initialize_graph(S2);
    EXPECT_EQ(S4, S2_);
}

TEST(DeleteVertexTest, xxx) {
    const WeightedGraph U1_ = {Vertices{1, 2, 3}, Edges{{1, 2}, {1, 3}, {2, 3}},
                               ReciprocalWeights{
                                   {{1, 2}, 1}, {{1, 3}, 1}, {{2, 3}, 1}}},
                        U2_ = {Vertices{1, 2, 3, 4, 6, 7, 8},
                               Edges{{1, 2},
                                     {1, 3},
                                     {1, 4},
                                     {1, 6},
                                     {2, 3},
                                     {2, 4},
                                     {2, 7},
                                     {3, 4},
                                     {6, 7},
                                     {6, 8},
                                     {7, 8}},
                               ReciprocalWeights{{{1, 2}, 1},
                                                 {{1, 3}, 1},
                                                 {{1, 4}, 1},
                                                 {{1, 6}, 2},
                                                 {{2, 3}, 1},
                                                 {{2, 4}, 1},
                                                 {{2, 7}, 2},
                                                 {{3, 4}, 1},
                                                 {{6, 7}, 1},
                                                 {{6, 8}, 1},
                                                 {{7, 8}, 1}}};
    const auto U1 = delete_vertex(S1, 4);
    EXPECT_EQ(U1, U1_);
    const auto U2 = delete_vertex(S4, 5);
    EXPECT_EQ(U2, U2_);
}

TEST(GetGraphKeepingKmTest, xxx) {
    const WeightedGraph U1_ = {Vertices{1, 2, 3, 4, 5},
                               Edges{{1, 2},
                                     {1, 3},
                                     {1, 4},
                                     {1, 5},
                                     {2, 3},
                                     {2, 4},
                                     {2, 5},
                                     {3, 4},
                                     {3, 5},
                                     {4, 5}},
                               ReciprocalWeights{{{1, 2}, 1},
                                                 {{1, 3}, 1},
                                                 {{1, 4}, 1},
                                                 {{1, 5}, 1},
                                                 {{2, 3}, 1},
                                                 {{2, 4}, 1},
                                                 {{2, 5}, 1},
                                                 {{3, 4}, 1},
                                                 {{3, 5}, 1},
                                                 {{4, 5}, 1}}},
                        U2_ = {Vertices{1, 5, 6},
                               Edges{
                                   {1, 5},
                                   {1, 6},
                                   {5, 6},
                               },
                               ReciprocalWeights{
                                   {{1, 5}, 1}, {{1, 6}, 1}, {{5, 6}, 1}}};
    const Vertices V1_ = Vertices{6, 7, 8}, V2_ = Vertices{2, 3, 4};
    const auto [U1, V1] = get_graph_keeping_km(S4);
    EXPECT_EQ(U1, U1_);
    EXPECT_EQ(V1, V1_);
    const auto [U2, V2] = get_graph_keeping_km(S3);
    EXPECT_EQ(U2, U2_);
    EXPECT_EQ(V2, V2_);
}

TEST(GetGraphOneDropKmTest, xxx) {
    const WeightedGraph
        U1_ = {Vertices{2, 3, 4, 5},
               Edges{{2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}},
               ReciprocalWeights{{{2, 3}, 1},
                                 {{2, 4}, 1},
                                 {{2, 5}, 1},
                                 {{3, 4}, 1},
                                 {{3, 5}, 1},
                                 {{4, 5}, 1}}},
        U2_ = {Vertices{5, 6},
               Edges{
                   {5, 6},
               },
               ReciprocalWeights{{{5, 6}, 1}}};
    const Vertices V1_ = Vertices{1, 6, 7, 8}, V2_ = Vertices{1, 2, 3, 4};
    const auto [U1, V1] = get_graph_one_drop_km(S4);
    EXPECT_EQ(U1, U1_);
    EXPECT_EQ(V1, V1_);
    const auto [U2, V2] = get_graph_one_drop_km(S3);
    EXPECT_EQ(U2, U2_);
    EXPECT_EQ(V2, V2_);
}

TEST(ExtractMaximumCliqueTest, xxx) {
    const Graph G1 = {Vertices{}, Edges{}}, G2 = {Vertices{4, 5, 9}, Edges{}},
                G3 = {Vertices{1, 3}, Edges{{1, 3}}},
                G4 = {Vertices{1, 2, 3}, Edges{{1, 2}, {1, 3}, {2, 3}}},
                G5 = {Vertices{1, 2, 3, 4},
                      Edges{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}}},
                G6 = {Vertices{1, 2, 3, 4, 5, 6, 7, 8}, Edges{{1, 2},
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
                                                              {7, 8}}};
    EXPECT_EQ(0, extract_maximum_clique(G1).size());
    EXPECT_EQ(1, extract_maximum_clique(G2).size());
    EXPECT_EQ(2, extract_maximum_clique(G3).size());
    EXPECT_EQ(3, extract_maximum_clique(G4).size());
    EXPECT_EQ(3, extract_maximum_clique(G5).size());
    EXPECT_EQ(5, extract_maximum_clique(G6).size());
}

TEST(BinarySearchItrTest, xxx) {
    const Vertices v = {2, 4, 5, 7, 8, 9};
    EXPECT_EQ(5, *binary_search_itr(v.cbegin(), v.cend(), 5));
    EXPECT_EQ(2, *binary_search_itr(v.cbegin(), v.cend(), 2));
}
}  // namespace
