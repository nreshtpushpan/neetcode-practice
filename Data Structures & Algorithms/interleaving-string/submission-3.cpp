class Solution {
public:
    vector<vector<int>> dp;
    bool recur(const string &s1, const string &s2, const string &s3, const int &n, int i, int j, int index) {
        if(index == n) {
            return i == (int)s1.size() && j == (int)s2.size();
        }
        if(i == (int)s1.size()) return s3.substr(index, n) == s2.substr(j, n);
        if(j == (int)s2.size()) return s3.substr(index, n) == s1.substr(i, n);
        if(dp[i][j] != -1) return dp[i][j];
        int ans = false;
        if(s1[i] == s3[index]) {
            ans |= recur(s1, s2, s3, n, i+1, j, index+1);
        }
        if(s2[j] == s3[index]) {
            ans |= recur(s1, s2, s3, n, i, j+1, index+1);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = (int)s3.size();
        int a = (int)s1.size();
        int b = (int)s2.size();
        if(a + b != n) return false;
        dp.resize(a+b, vector<int> (a+b, -1));
        return recur(s1, s2, s3, n, 0, 0, 0);
    }
};
