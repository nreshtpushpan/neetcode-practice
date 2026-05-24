class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = (int)heights.size();
        int c = (int)heights[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        pq.push({0, 0, 0});
        int maxEffort = 0;
        while(!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();
            maxEffort = max(maxEffort, effort);
            if(x == r-1 && y == c-1) return maxEffort;
            if(vis[x][y]) continue;
            vis[x][y] = true;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i*i + j*j != 1) continue;
                    int xx = x + i;
                    int yy = y + j;
                    if(xx < 0 || xx == r || yy < 0 || yy == c) continue;
                    if(vis[xx][yy]) continue;
                    pq.push({abs(heights[xx][yy] - heights[x][y]), xx, yy});
                }
            }
        }
        return r*c;
    }
};