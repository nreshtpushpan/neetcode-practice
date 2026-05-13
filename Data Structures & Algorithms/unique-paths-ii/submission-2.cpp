class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int r = (int)g.size();
        int c = (int)g[0].size();
        if(g[r-1][c-1] || g[0][0]) return 0;
        vector<vector<int>> dp(r, vector<int> (c, 0));
        for(int i = 0; i < r; i++) {
            if(g[i][0]) break;
            dp[i][0] = 1;
        }
        for(int i = 0; i < c; i++) {
            if(g[0][i]) break;
            dp[0][i] = 1;
        }
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(g[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};