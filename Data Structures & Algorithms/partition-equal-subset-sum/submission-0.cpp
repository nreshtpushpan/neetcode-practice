class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int target = sum/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto num: nums) {
            for(int j = target; j > 0 && j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
