class Solution {
public:
    int R, C;
    void bfs(const vector<vector<int>>& g, const vector<pair<int, int>> &start, vector<vector<bool>> &vis) {
        queue<pair<int,int>> q;
        for(auto point : start) q.push(point);
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i*i + j*j != 1) continue;
                    int xx = x + i;
                    int yy = y + j;
                    if(xx < 0 || yy < 0 || xx == R || yy == C) continue;
                    if(vis[xx][yy] || g[x][y] > g[xx][yy]) continue;
                    q.push({xx, yy});
                } 
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& g) {
        R = (int)g.size();
        C = (int)g[0].size();
        vector<pair<int,int>> pacific, atlantic;
        for(int i = 0; i < R; i++) {
            pacific.push_back({i, 0});      // left col
            atlantic.push_back({i, C-1});   // right col
        }
        for(int j = 0; j < C; j++) {
            pacific.push_back({0, j});      // top row
            atlantic.push_back({R-1, j});   // bottom row
        }

        vector<vector<bool>> visP(R, vector<bool>(C, false));
        vector<vector<bool>> visA(R, vector<bool>(C, false));
        bfs(g, pacific, visP);
        bfs(g, atlantic, visA);
        vector<vector<int>> res;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(visP[i][j] && visA[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
