class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        if(n <= 1) return 0;
        if(n < 3) return min(cost[0], cost[1]);
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};
