class Solution {
public:
    unordered_map<int, bool> dp;
    bool recur(string s, int n, int minJump, int maxJump, int index) {
        if(index >= n) return false;
        if(s[index] == '1') return false;
        if(index == n-1 && s[index] == '0') return true;
        if(dp.count(index)) return dp[index];
        bool isPossible = false;
        for(int i = minJump; i <= maxJump; i++) {
            if(index + i >= n) break;
            isPossible |= recur(s, n, minJump, maxJump, i + index);
        }
        return dp[index] = isPossible;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = (int)s.size();
        return recur(s, n, minJump, maxJump, 0);
    }
};