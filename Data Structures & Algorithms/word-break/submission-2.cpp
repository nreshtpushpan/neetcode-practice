class Solution {
public:
    bool recur(const unordered_set<string> &dic, const int &MAX_SIZE, const string &s, int index, vector<int>& memo) {
        int n = (int)s.size();
        if(index == n) return true;
        if(memo[index] != -1) return memo[index];
        string cur = "";
        for(int i = index; i < n; i++) {
            cur += s[i];
            if(dic.find(cur) != dic.end()) {
                if(recur(dic, MAX_SIZE, s, i+1, memo)) return memo[index] = true;
            }
            if(cur.size() > MAX_SIZE) break;
        }
        return memo[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dic;
        int MAX_SIZE = 0;
        for(auto word : wordDict) {
            dic.insert(word);
            MAX_SIZE = max(MAX_SIZE, (int)word.size());
        }
        vector<int> memo(n, -1);
        return recur(dic, MAX_SIZE, s, 0, memo);
    }
};