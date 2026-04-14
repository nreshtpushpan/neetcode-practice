class Solution {
public:
    bool dfs(const vector<vector<int>> &g, vector<bool> &visit, int node, int parent) {
        visit[node] = true;
        bool isTree = true;
        for(auto child : g[node]) {
            if(child == parent) continue;
            if(visit[child]) return false;
            isTree &= dfs(g, visit, child, node);
        }
        return isTree;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = (int)edges.size();
        if(m != n-1) return false;
        vector<vector<int>> g(n+1);
        for(auto edge: edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            g[n1].push_back(n2);
            g[n2].push_back(n1);
        }
        vector<bool> visit(n+1, false);
        if(!dfs(g, visit, 0, -1)) return false;
        for(int i = 0; i < n; i++) if(!visit[i]) return false;
        return true;
    }
};
