class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        int freshFruits = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(g[i][j] == 1) ++freshFruits;
                else if(g[i][j] == 2) q.push({i, j});
            }
        }
        if(freshFruits == 0) return 0;
        int timeTaken = 0;
        while(!q.empty()) {
            int siz = q.size();
            while(siz--) {
                auto[a, b] = q.front();
                q.pop();
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        if(i*i + j*j != 1) continue;
                        int aa = a + i;
                        int bb = b + j;
                        if(aa < 0 || aa == r || bb < 0 || bb == c) continue;
                        if(g[aa][bb] == 1) {
                            g[aa][bb] = 2;
                            q.push({aa, bb});
                            --freshFruits;
                        }
                    }
                }
            }
            ++timeTaken;
            if(freshFruits == 0) return timeTaken;
        }
        return -1;
    }
};
