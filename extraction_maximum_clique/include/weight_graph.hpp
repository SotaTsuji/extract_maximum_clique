#ifndef INCLUDED_weight_graph_hpp_
#define INCLUDED_weight_graph_hpp_

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using Vertex = vector<int>;
using Edge = unordered_set<pair<int, int>>;
using Weight = unordered_map<pair<int, int>, int>;

namespace std {
template <>
class hash<pair<int, int>> {
   public:
    size_t operator()(const pair<int, int>& x) const {
        return hash<int>()(x.first) ^hash<int>()(x.second);
    }
};
}

struct WeightGraph {
    Vertex v;
    Edge e;
    Weight w;
};

#endif
