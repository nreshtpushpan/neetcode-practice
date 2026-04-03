class Solution {
public:
    vector<vector<int>> dp;
    int recur(const int &n, const int &m, string &w1, string &w2, int i, int j) {
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(w1[i] == w2[j]) {
            return dp[i][j] = recur(n, m, w1, w2, i-1, j-1);
        }
        int insert = 1 + recur(n, m, w1, w2, i, j-1);
        int del = 1 + recur(n, m, w1, w2, i-1, j);
        int replace = 1 + recur(n, m , w1, w2, i-1, j-1);
        return dp[i][j] = min(insert, min(del, replace));
    }
    int minDistance(string word1, string word2) {
        int n = (int)word1.size();
        int m = (int)word2.size();
        dp.resize(n, vector<int> (m, INT_MAX));
        return recur(n, m, word1, word2, n-1, m-1);
    }
};
