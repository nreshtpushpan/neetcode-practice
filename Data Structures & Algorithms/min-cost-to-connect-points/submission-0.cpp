class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>, int> disMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int n = (int)points.size();
        
        for(int j = 1; j < n; j++) {
            int dis = abs(points[0][0] - points[j][0]) + abs(points[0][1] - points[j][1]);
            pq.push({dis, j});
            disMap[{points[j][0], points[j][1]}] = dis;
        }
        
        vector<bool> vis(n, false);
        vis[0] = true;
        while(!pq.empty()) {
            auto [dis, index] = pq.top();
            pq.pop();
            if(vis[index]) continue;
            vis[index] = true;
            if(disMap[{points[index][0], points[index][1]}] < dis) continue;
            for(int i = 0; i < n; i++) {
                if(i == index || vis[i]) continue;
                int dis = abs(points[i][0] - points[index][0]) + abs(points[index][1] - points[i][1]);
                if(disMap[{points[i][0], points[i][1]}] > dis) {
                    pq.push({dis, i});
                    disMap[{points[i][0], points[i][1]}] = dis;
                }
            }
        }
        int totalCost = 0;
        for(auto it : disMap) {
            totalCost += it.second;
            //cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
        }
        return totalCost;
    }
};
