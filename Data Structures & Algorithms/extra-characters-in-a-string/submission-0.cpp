class Solution {
public:
    vector<int> dp;
    int recur(const string &str, const int &n, const unordered_set<string> &dic, int index) {
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = 1 + recur(str, n, dic, index+1);
        for(int j = index + 1; j <= n; j++) {
            if(dic.count(str.substr(index, j-index))) ans = min(ans, recur(str, n, dic, j));
        }
        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dic(dictionary.begin(), dictionary.end());
        int n = (int)s.size();
        dp.resize(n, -1);
        return recur(s, n, dic, 0);
    }
};