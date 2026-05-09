class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int recur(string s, string t, int i, int j) {
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(int index = i; index < n; index++) {
            if(s[index] == t[j]) {
                res += recur(s, t, index+1, j+1);
            }
        }
        return dp[i][j] = res;
    } 
    int numDistinct(string s, string t) {
        n = (int)s.size();
        m = (int)t.size();
        dp.resize(n, vector<int> (m, -1));
        return recur(s, t, 0, 0);
    }
};
