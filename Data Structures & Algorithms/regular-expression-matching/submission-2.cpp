class Solution {
public:
    vector<vector<int>> dp;
    bool recur(const string &s, const string &p, const int &n, const int &m, int i, int j){
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n) {
            if(j+1 < m && p[j+1] == '*') return recur(s, p, n, m, i, j+2);
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool isMat = false;
        if(j+1 < m && p[j+1] == '*') {
            isMat |= recur(s, p, n, m, i, j+2);
            int k = i;
            while(k < n && (p[j] == s[k] || p[j] == '.')) {
                isMat |= recur(s, p, n, m, k+1, j+2);
                ++k;
            }
        } else {
            if(s[i] == p[j] || p[j] == '.') {
                isMat |= recur(s, p, n, m, i+1, j+1);
            }
        }
        return dp[i][j] = isMat;
    }
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        dp.resize(n, vector<int> (m, -1));
        return recur(s, p, n, m, 0, 0);
    }
};
