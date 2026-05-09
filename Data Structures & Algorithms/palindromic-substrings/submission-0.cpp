class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        if(n == 1) return n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) dp[i][i] = true;
        int res = n;
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
