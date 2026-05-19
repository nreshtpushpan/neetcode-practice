class Solution {
public:
    vector<vector<int>> dp;
    bool recur(const string &str, const int &n, int index, int open) {
       // if(open < 0) return false;
        if(index == n) return (open == 0);
        if(dp[index][open] != -1) return dp[index][open];
        bool isValid = false;
        if(str[index] == '(') {
            isValid = recur(str, n, index + 1, open+1);
        } else if (str[index] == ')') {
            if(open) isValid = recur(str, n, index + 1, open-1);
            else return dp[index][open] = false;
        } else {
            isValid |= recur(str, n, index + 1, open+1) || recur(str, n, index + 1, open);
             if(open) isValid |= recur(str, n, index + 1, open-1);
        }
        return dp[index][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = (int)s.size();
        dp.resize(n+1, vector<int> (n+1, -1));
        return recur(s, n, 0, 0);
    }
};
