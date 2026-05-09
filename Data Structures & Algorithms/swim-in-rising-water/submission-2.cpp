class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c, false));
    
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int curVal = t[0];
            int rr = t[1];
            int cc = t[2];
            if(vis[rr][cc]) continue;
            vis[rr][cc] = true;
            int val = max(curVal, grid[rr][cc]);
            if(rr == r-1 && cc == c-1) return val;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i*i + j*j != 1) continue;
                    int ii = i + rr;
                    int jj = j + cc;
                    if(ii < 0 || ii == r || jj < 0 || jj == c) continue;
                    pq.push({val, ii, jj});
                }
            }
        }
        return INT_MAX;
    }
};
