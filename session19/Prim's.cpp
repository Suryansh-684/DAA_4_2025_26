#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
struct Edge {
    int weight;
    int u;
    int v;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

std::vector<Edge> prim_mst(const std::unordered_map<int, std::vector<std::pair<int, int>>>& graph) {
    if (graph.empty()) {
        return {};
    }
    
    std::unordered_set<int> visited;
    std::vector<Edge> mst;
    int start_vertex = graph.begin()->first;
    visited.insert(start_vertex);
    
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    
    for (const auto& edge : graph.at(start_vertex)) {
        int neighbor = edge.first;
        int weight = edge.second;
        pq.push({weight, start_vertex, neighbor});
    }
    
    while (!pq.empty() && visited.size() < graph.size()) {
        Edge current = pq.top();
        pq.pop();
        
        if (visited.find(current.v) != visited.end()) {
            continue;
        }
        
        visited.insert(current.v);
        mst.push_back(current);
        
        if (graph.find(current.v) != graph.end()) {
            for (const auto& edge : graph.at(current.v)) {
                int neighbor = edge.first;
                int edge_weight = edge.second;
                if (visited.find(neighbor) == visited.end()) {
                    pq.push({edge_weight, current.v, neighbor});
                }
            }
        }
    }
    
    return mst;