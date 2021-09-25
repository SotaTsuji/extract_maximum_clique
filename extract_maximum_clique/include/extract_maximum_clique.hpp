// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#pragma once

#include "graph.hpp"

namespace extract_maximum_clique {
bool is_complete_graph(const WeightedGraph& T);
// WeightedGraph initialize_graph(WeightedGraph S);
// WeightedGraph delete_vertex(const WeightedGraph& T, const Vertex v);
// pair<WeightedGraph, Vertices> get_graph_keeping_km(WeightedGraph T);
// pair<WeightedGraph, Vertices> get_graph_one_drop_km(const WeightedGraph& U);
// WeightedGraph delete_vertices(const WeightedGraph& U, const Vertices& Vc);
// Vertices extract_maximum_clique(const Graph& G);
}  // namespace extract_maximum_clique
