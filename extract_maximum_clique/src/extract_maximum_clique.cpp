// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/extract_maximum_clique.hpp"

#include "../include/calculate_km.hpp"
#include "../include/graph.hpp"

namespace extract_maximum_clique {
// Algorithm 1
bool is_complete_graph(const WeightedGraph& T) {
    const auto n_e = T.e.size(), n_v = T.v.size();
    if (n_e == (n_v * n_v - n_v) / 2) {
        for (auto i = 0; i < n_v - 1; ++i) {
            for (auto j = i + 1; j < n_v; ++j) {
                if (T.rw.at({T.v[i], T.v[j]}) != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
}  // namespace extract_maximum_clique
