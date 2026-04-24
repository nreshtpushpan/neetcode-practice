class Solution {
public:
    void dfs(const vector<vector<char>> &g, const int &n, const int &m, int r, int c, vector<vector<bool>> &visit) {
        if(r < 0 || c < 0 || r == n || c == m) return;
        if(visit[r][c]) return;
        visit[r][c] = true;
        if(g[r][c] == '0') return;
        dfs(g, n, m, r+1, c, visit);
        dfs(g, n, m, r, c+1, visit);
        dfs(g, n, m, r-1, c, visit);
        dfs(g, n, m, r, c-1, visit);        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = (int)grid.size();
        if(n == 0) return 0;
        int m = (int)grid[0].size();
        vector<vector<bool>> visit(n, vector<bool> (m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(!visit[i][j] && grid[i][j] == '1') {
                    ++count;
                    dfs(grid, n, m, i, j, visit);
                }
            }
        }
        return count;
    }
};
