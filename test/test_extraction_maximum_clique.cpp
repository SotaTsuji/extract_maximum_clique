#include "extraction_maximum_clique.hpp"
#include "gtest/gtest.h"
#include "weight_graph.hpp"

using namespace std;
WeightGraph T1, T2, T3, T4;

static int create_graph = []() {
    T1.v = {1, 2};
    T1.e = {{1, 2}};
    T1.w[{1, 2}] = 1;
    T2.v = {2, 3, 5};
    T2.e = {{2, 3}, {2, 5}, {3, 5}};
    T2.w[{2, 3}] = T2.w[{2, 5}] = T2.w[{3, 5}] = 1;
    T3.v = {2, 3, 5};
    T3.e = {{2, 3}, {2, 5}};
    T3.w[{2, 3}] = T3.w[{2, 5}] = 1;
    T4.v = {2, 3, 5};
    T4.e = {{2, 3}, {2, 5}, {3, 5}};
    T4.w[{2, 3}] = T4.w[{2, 5}] = 1;
    T4.w[{3, 5}] = 2;
    return 0;
}();

TEST(IsCompleteGraphTest, True) {
    EXPECT_EQ(true, is_complete_graph(T1));
    EXPECT_EQ(true, is_complete_graph(T2));
}

TEST(IsCompleteGraphTest, False) {
    EXPECT_EQ(false, is_complete_graph(T3));
    EXPECT_EQ(false, is_complete_graph(T4));
}
