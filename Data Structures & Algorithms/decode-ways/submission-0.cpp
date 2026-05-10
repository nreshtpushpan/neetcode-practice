class Solution {
public:
    vector<int> dp;
    int recur(const string& s, const int& n, int i) {
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0;
        int ans = recur(s, n, i+1);
        if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            ans += recur(s, n, i+2);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = (int)s.size();
        dp.resize(n, -1);
        return recur(s, n, 0);
    }
};
