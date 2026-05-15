class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        int r = (int)m.size();
        int c = (int)m[0].size();
        vector<vector<int>> trans(c, vector<int> (r));
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                trans[i][j] = m[j][i];
            }
        }
        return trans;
    }
};