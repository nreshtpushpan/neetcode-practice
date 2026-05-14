class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<int> disMap(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(int j = 1; j < n; j++) {
            int dis = abs(points[0][0] - points[j][0]) + abs(points[0][1] - points[j][1]);
            pq.push({dis, j});
            disMap[j] = dis;
        }
        
        vector<bool> vis(n, false);
        vis[0] = true;
        int totalCost = 0;
        while(!pq.empty()) {
            auto [dis, index] = pq.top();
            pq.pop();
            if(vis[index]) continue;
            vis[index] = true;
            totalCost += dis;
            for(int i = 0; i < n; i++) {
                if(vis[i]) continue;
                int dis = abs(points[i][0] - points[index][0]) + abs(points[index][1] - points[i][1]);
                if(disMap[i] > dis) {
                    pq.push({dis, i});
                    disMap[i] = dis;
                }
            }
        }
        return totalCost;
    }
};
