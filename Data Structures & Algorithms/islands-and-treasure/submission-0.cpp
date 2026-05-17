class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 0) q.push({i ,j});
            }
        }
        int mod = INT_MAX;
        int dis = 0;
        while(!q.empty()) {
            int siz = q.size();
            for(int k = 0; k < siz; k++) {
                auto [x, y] = q.front();
                q.pop();
                if(vis[x][y]) continue;
                vis[x][y] = true;
                grid[x][y] = dis;
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        if(i*i + j*j != 1) continue;
                        int xx = x + i;
                        int yy = y + j;
                        if(xx < 0 || xx == r || yy < 0 || yy == c) continue;
                        if(vis[xx][yy]) continue;
                        if(grid[xx][yy] != mod) continue;
                        q.push({xx, yy});
                    }
                }
            }
            dis++;
        }
    }
};
