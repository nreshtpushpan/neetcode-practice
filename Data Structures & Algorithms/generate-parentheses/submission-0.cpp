class Solution {
public:
    vector<string> results;
    void recur(const int &n, int open, int close, string &cur) {
        if(open == n && close == n) {
            results.push_back(cur);
            return;
        }
        if(open > close) {
            cur.push_back(')');
            recur(n, open, close + 1, cur);
            cur.pop_back();
        }
        if(open < n) {
            cur.push_back('(');
            recur(n, open + 1, close, cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        recur(n, 0, 0, cur);
        return results;
    }
};
