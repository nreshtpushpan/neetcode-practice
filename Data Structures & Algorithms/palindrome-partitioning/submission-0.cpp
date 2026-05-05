class Solution {
public:
    vector<vector<bool>> dp;
    
    void recur(const string &s, int index, vector<string> &part, vector<vector<string>> &res) {
        if(index == s.size()) {
            res.push_back(part);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            if(dp[index][i]) {
                part.push_back(s.substr(index, i - index + 1));
                recur(s, i+1, part, res);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        dp.resize(n, vector<bool> (n, false));
        for(int l = 0; l < n; l++) {
            for(int i = 0; i+l < n; i++) {
                int j = i+l;
                if(j - i <= 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
            }
        }
        vector<string> part;
        vector<vector<string>> res;
        recur(s, 0, part, res);
        return res;
    }
};
