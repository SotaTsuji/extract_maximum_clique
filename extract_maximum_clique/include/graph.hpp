// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace extract_maximum_clique {
using Vertex = int;
using Vertices = std::vector<Vertex>;
using Edge = std::pair<Vertex, Vertex>;
using Edges = std::unordered_set<Edge>;
using ReciprocalWeights = std::unordered_map<Edge, int>;
}  // namespace extract_maximum_clique

namespace std {
using extract_maximum_clique::Edge;
template <>
class hash<Edge> {
   public:
    size_t operator()(const Edge& x) const {
        return hash<int>()(x.first) ^ hash<int>()(x.second);
    }
};
}  // namespace std

namespace extract_maximum_clique {
struct Graph {
    Vertices v;
    Edges e;
};

struct WeightedGraph : Graph {
    ReciprocalWeights rw;
};
}  // namespace extract_maximum_clique
