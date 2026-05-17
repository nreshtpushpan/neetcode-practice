class Solution {
public:
    int R, C;
    vector<vector<int>> dp;
    int dfs(const vector<vector<int>>& matrix, int x, int y) {
        if(dp[x][y] != -1) return dp[x][y];
        int result = 1;
       // cout<<matrix[x][y]<<" "<<x<<"-"<<y<<endl;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i*i + j*j != 1) continue;
                int xx = x + i;
                int yy = y + j;
                if(xx < 0 || yy < 0 || xx == R || yy == C) continue;
                if(matrix[xx][yy] <= matrix[x][y]) continue;
                result = max(result, 1 + dfs(matrix, xx, yy));
            }
        }
       // cout<<matrix[x][y]<<" "<<x<<"-"<<y<<" : "<<result<<endl;
        return dp[x][y] = result;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        R = (int)matrix.size();
        C = (int)matrix[0].size();
        dp.resize(R, vector<int> (C, -1));
        int maxPath = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                maxPath = max(maxPath, dfs(matrix, i, j));
            }
        }
        return maxPath;
    }
};
