// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using Vertex = int;
using Vertices = vector<Vertex>;
using Edge = pair<Vertex, Vertex>;
using Edges = unordered_set<Edge>;
using ReciprocalWeights = unordered_map<Edge, int>;

namespace std {
template <>
class hash<Edge> {
   public:
    size_t operator()(const pair<int, int>& x) const {
        return hash<int>()(x.first) ^ hash<int>()(x.second);
    }
};
}  // namespace std

struct Graph {
    Vertices v;
    Edges e;
};

struct WeightedGraph : Graph {
    ReciprocalWeights rw;
};
