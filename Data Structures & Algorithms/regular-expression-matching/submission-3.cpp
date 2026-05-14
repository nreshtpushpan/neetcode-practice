class Solution {
public:
    vector<vector<int>> dp;
    bool recur(const string &s, const string &p, const int &n, const int &m, int i, int j){
        if(j == m) return (i == n);
        if(dp[i][j] != -1) return dp[i][j];
        bool isMat = i < n && (p[j] == s[i] || p[j] == '.');
        if(j+1 < m && p[j+1] == '*') {
            dp[i][j] = (isMat && (recur(s, p, n, m, i+1, j)) || recur(s, p, n, m, i, j+2));
        } else {
            dp[i][j] = isMat && recur(s, p, n, m, i+1, j+1);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        dp.resize(n+1, vector<int> (m+1, -1));
        return recur(s, p, n, m, 0, 0);
    }
};
