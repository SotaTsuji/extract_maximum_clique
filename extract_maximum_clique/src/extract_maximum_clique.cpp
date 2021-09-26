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

// Algorithm 3
WeightedGraph delete_vertex(const WeightedGraph& T, const Vertex v) {
    const int km = get_km(T);
    auto T_ = T;
    T_.v.erase(binary_search_itr(T_.v.cbegin(), T_.v.cend(), v));
    auto itr = T_.e.cbegin();
    while (itr != T_.e.cend()) {
        if ((*itr).first == v || (*itr).second == v) {
            T_.rw.erase(*itr);
            itr = T_.e.erase(itr);
        } else {
            ++itr;
        }
    }
    if (get_km(T_) == km) {
        for (auto i = 0; i < T_.v.size() - 1; ++i) {
            for (auto j = i + 1; j < T_.v.size(); ++j) {
                const Edge e = {T_.v[i], T_.v[j]};
                if (!T_.e.contains(e)) {
                    auto T__ = T_;
                    T__.e.insert(e);
                    T__.rw[e] = 2;
                    if (get_km(T__) < km) {
                        return T__;
                    }
                }
            }
        }
    }
    return T_;
}

// Algorithm 4
pair<WeightedGraph, Vertices> get_graph_keeping_km(WeightedGraph T) {
    const int km = get_km(T);
    Vertices Va;
    const auto V_ = T.v;
    for (auto v : V_) {
        auto T_ = delete_vertex(T, v);
        if (get_km(T_) == km) {
            Va.push_back(v);
            T = T_;
        }
    }
    return {T, Va};
}

Vertices_citr binary_search_itr(Vertices_citr first, Vertices_citr last,
                                Vertex v) {
    const auto itr = first + (last - first) / 2;
    if (*itr == v) {
        return itr;
    } else if (*itr > v) {
        return binary_search_itr(first, itr, v);
    } else {
        return binary_search_itr(itr + 1, last, v);
    }
}
}  // namespace extraction_of_maximum_clique
