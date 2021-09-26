// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace extraction_of_maximum_clique {
using Vertex = int;
using Vertices = std::vector<Vertex>;
using Edge = std::pair<Vertex, Vertex>;
using Edges = std::unordered_set<Edge>;
using ReciprocalWeights = std::unordered_map<Edge, int>;
}  // namespace extraction_of_maximum_clique

namespace std {
using extraction_of_maximum_clique::Edge;
template <>
class hash<Edge> {
   public:
    size_t operator()(const Edge& x) const {
        return hash<int>()(x.first) ^ hash<int>()(x.second);
    }
};
}  // namespace std

namespace extraction_of_maximum_clique {
struct Graph {
    Vertices v;
    Edges e;
    bool operator==(const Graph& other) const {
        return (v == other.v) && (e == other.e);
    }
    bool operator!=(const Graph& other) const { return !(*this == other); }
};

struct WeightedGraph : Graph {
    ReciprocalWeights rw;
    Graph j, k;
    bool operator==(const WeightedGraph& other) const {
        return (Graph){v, e} == (Graph){other.v, other.e} && (rw == other.rw);
    }
    bool operator!=(const WeightedGraph& other) const {
        return !(*this == other);
    }
};
}  // namespace extraction_of_maximum_clique
