class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        int n = (int)s.size();
        if(s[0] == '1' || s[n-1] == '1') return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;
            for(int k = minJump; k <= maxJump; k++) {
                int j = i + k;
                if(j == n) break;
                if(s[j] == '0') dp[j] = true;
            }
        }
        return dp[n-1];
    }
};