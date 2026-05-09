class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, INT_MAX));
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        auto cmp = [](const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, decltype(cmp)> pq(cmp);
        pq.push({grid[0][0], {0, 0}});
        dp[0][0] = grid[0][0];
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int curVal = t.first;
            int rr = t.second.first;
            int cc = t.second.second;
            if(vis[rr][cc]) continue;
            vis[rr][cc] = true;
            //if(dp[rr][cc] > max(curVal, grid[rr][cc]))continue;
            dp[rr][cc] = min(dp[rr][cc], max(curVal, grid[rr][cc]));
            if(rr == r-1 && cc == c-1) return dp[rr][cc];
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i*i + j*j != 1) continue;
                    int ii = i + rr;
                    int jj = j + cc;
                    if(ii < 0 || ii == r || jj < 0 || jj == c) continue;
                    pq.push({dp[rr][cc], {ii, jj}});
                }
            }
        }
        return 0;
    }
};
