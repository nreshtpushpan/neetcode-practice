class Solution {
public:
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = (int)nums.size();
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum%k) return false;
        int target = sum/k;
        int N = 1 << n;
        vector<int> dp(N, -1);
        dp[0] = 0;
        for(int mask = 0; mask < N; mask++) {
            if(dp[mask] == -1) continue;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue;
                if(dp[mask] + nums[i] > target) continue;
                dp[mask | (1 << i)] = (dp[mask] + nums[i])%target;
            }
        }
        return dp[N-1] == 0;
    }
};