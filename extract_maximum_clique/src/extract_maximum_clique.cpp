// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/extract_maximum_clique.hpp"

#include "../include/calculate_km.hpp"
#include "../include/graph.hpp"
using namespace std;

// Algorithm 1
bool is_complete_graph(const WeightedGraph& T) {
    const auto es = T.e.size(), vs = T.v.size();
    if (es == (vs * vs - vs) / 2) {
        for (auto i = 0; i < vs - 1; ++i) {
            for (auto j = i + 1; j < vs; ++j) {
                if (T.rw.at({T.v[i], T.v[j]}) != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
