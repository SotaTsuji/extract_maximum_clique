// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/extract_maximum_clique.hpp"

#include "../include/calculate_km.hpp"
#include "../include/graph.hpp"

namespace extraction_of_maximum_clique {
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
// Algorithm 2
WeightedGraph initialize_graph(WeightedGraph S) {
    int km = get_km(S);
    int n_v = S.v.size();
    for (auto i = 0; i < n_v - 1; ++i) {
        for (auto j = i + 1; j < n_v; ++j) {
            if (!S.e.contains({S.v[i], S.v[j]})) {
                auto S_ = S;
                S_.e.insert({S.v[i], S.v[j]});
                S_.rw[{S.v[i], S.v[j]}] = 2;
                const int km_ = get_km(S_);
                if (km_ < km) {
                    S = S_;
                    km = km_;
                }
            }
        }
    }
    return S;
}
}  // namespace extraction_of_maximum_clique
