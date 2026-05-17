class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findP(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findP(parent[node]);
    }   

    bool merge(int a, int b) {
        int pa = findP(a);
        int pb = findP(b);
        if(pa == pb) return true;
        if(rank[pa] >= rank[pb]) {
            parent[pb] = pa;
            rank[pb] += rank[pa];
        } else {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        DSU dsu(n+1);
        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if(dsu.merge(a, b)) return {a, b};
        }
        return {};
    }
};
