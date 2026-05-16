class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        bitset<100> rowHash = 0, colHash = 0;
        int r = (int)g.size();
        int c= (int)g[0].size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(g[i][j] == 0) {
                    rowHash.set(i);
                    colHash.set(j);
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(rowHash.test(i) || colHash.test(j)) {
                    g[i][j] = 0;
                }
            }
        }
    }
};
