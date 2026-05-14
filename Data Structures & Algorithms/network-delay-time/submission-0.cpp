class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> cost(n+1, vector<int> (n+1));
        vector<vector<int>> g(n+1);
        for(auto edge : times) {
            g[edge[0]].push_back(edge[1]);
            cost[edge[0]][edge[1]] = edge[2];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int totalRequiredNodes = n-1;
        for(auto node : g[k]) {
            pq.push({cost[k][node], node});
        }
        vector<bool> vis(n+1, false);
        vis[k] = true;
        while(!pq.empty()) {
            auto [timeTaken, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            if(--totalRequiredNodes == 0) return timeTaken;
            for(auto child: g[node]) {
                pq.push({cost[node][child] + timeTaken, child});
            }
        }
        return -1;
    }
};
