class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int maxL = 1, start = 0;
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(len <= 2) dp[i][j] = s[i] == s[j];
                else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                if(dp[i][j] && len > maxL) {
                    maxL = len;
                    start = i;
                }
            }
        }
        return s.substr(start, maxL);
    }
};
