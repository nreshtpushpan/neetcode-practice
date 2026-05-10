class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = (int)stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int sumRequired = total/2;
        vector<bool> dp(sumRequired + 1, false);
        dp[0] = true;
        for(int j = 0; j < n; j++) {
            for(int i = sumRequired; i >= stones[j]; i--) {  // ✅ backward = 0/1 knapsack
                dp[i] = dp[i] | dp[i - stones[j]];
        }
}
        for(int j = sumRequired; j >= 0; j--)
            if(dp[j]) return total - 2*j;
        return total;
    }
};