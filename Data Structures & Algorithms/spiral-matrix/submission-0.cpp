class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int n = (int)m.size();
        int c = m[0].size();
        vector<int> ans(n*c);
        int index = 0;
        int l = 0, r = c-1, t = 0, b = n-1;
        while(l <= r && t <= b) {
            for(int i = l; i <= r && (l <= r && t <= b); i++){
                ans[index++] = m[t][i];
            }
            ++t;
            for(int i = t; i <= b && (l <= r && t <= b); i++) {
                ans[index++] = m[i][r];
            }
            --r;
            for(int i = r; i >= l && (l <= r && t <= b); i--) {
                ans[index++] = m[b][i];
            }
            --b;
            for(int i = b; i >= t && (l <= r && t <= b); i--) {
                ans[index++] = m[i][l];
            }
            ++l;
        }
        return ans;
        
    }
};