class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> inDegree(n, 0);
        vector<vector<int>> g(n);
        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
            inDegree[a]++;
            inDegree[b]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 1) q.push(i);
        }
        int remNodes = n;
        while(remNodes > 2) {
            int siz = q.size();
            remNodes -= siz;
            for(int k = 0; k < siz; k++) {
                auto node = q.front();
                q.pop();
                for(auto child : g[node]) {
                    inDegree[child]--;
                    if(inDegree[child] == 1) q.push(child);
                }
            }
        }
        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};