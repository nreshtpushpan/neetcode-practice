class Solution {
public:
    vector<int> parent, rank;
    int findP(int node) {
        if(parent[node] == node) return node;
        return findP(parent[node]);
    }
    void joinP(int a, int b) {
        int pa = findP(a);
        int pb = findP(b);
        if(pa == pb) return;
        if(rank[a] < rank[b]) {
            parent[pb] = pa;
            rank[pb]++;
        } else {
            parent[pa] = pb;
            rank[pa]++;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for(auto edge : edges) {
            joinP(edge[0], edge[1]);
        }
        vector<int> count(n, 0);
        for(int i = 0; i < n; i++) count[findP(i)]++;
        int res = 0;
        for(int i = 0; i < n; i++) res += (count[i] > 0);
        return res;
    }
};
