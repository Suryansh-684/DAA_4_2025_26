#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false; // Already in same set
        
        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

// Edge structure
struct Edge {
    int u, v, weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Kruskal's algorithm implementation
vector<Edge> kruskal(int n, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;
    
    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            
            // MST has n-1 edges
            if (mst.size() == n - 1) break;
        }
    }
    
    cout << "Total MST weight: " << totalWeight << endl;
    return mst;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<Edge> edges(m);
    cout << "Enter edges (u v weight):" << endl;
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    vector<Edge> mst = kruskal(n, edges);
    
    cout << "MST edges:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }
    
    return 0;
}