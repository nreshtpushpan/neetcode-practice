class Solution {
public:
    vector<vector<bool>> vis;
    int bfs(const vector<vector<int>>& grid, const int &r, const int &c, int i, int j) {
        int maxArea = 0;
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;
            ++maxArea;
            for(int a = -1; a <= 1; a++) {
                for(int b = -1; b <= 1; b++) {
                    if(a*a + b*b != 1) continue;
                    int ii = x + a;
                    int jj = y + b;
                    if(ii < 0 || jj < 0 || ii == r || jj == c) continue;
                    if(vis[ii][jj]) continue;
                    if(grid[ii][jj] == 0) continue;
                    q.push({ii, jj});
                }
            }
            
        }
        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        vis.resize(r, vector<bool>(c, false));
        int area = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    area = max(area, bfs(grid, r, c, i, j));
                }
            }
        }
        return area;

    }
};
