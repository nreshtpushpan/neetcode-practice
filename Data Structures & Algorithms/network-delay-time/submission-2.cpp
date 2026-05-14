class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n == 1) return 0;
        vector<vector<pair<int,int>>> g(n+1);
        for(auto edge : times) {
            g[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int totalRequiredNodes = n;
        pq.push({0, k});
        vector<bool> vis(n+1, false);
        while(!pq.empty()) {
            auto [timeTaken, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            if(--totalRequiredNodes == 0) return timeTaken;
            for(auto child: g[node]) {
                pq.push({child.second + timeTaken, child.first});
            }
        }
        return -1;
    }
};
