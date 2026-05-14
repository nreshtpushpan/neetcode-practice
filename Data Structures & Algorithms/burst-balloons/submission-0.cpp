class Solution {
public:
    vector<vector<int>> dp;
    int recur(const vector<int> &nums, const int &n, int l, int r) {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];    
        dp[l][r] = 0;
        for(int i = l; i <= r; i++) {
            int left = (l-1 < 0) ? 1 : nums[l-1];
            int right = (r+1 == n) ? 1 : nums[r+1];
            int count = left * nums[i] * right;
            count += recur(nums, n, l, i-1) + recur(nums, n, i+1, r);
            dp[l][r] = max(dp[l][r], count);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        dp.resize(n, vector<int> (n, -1));
        return recur(nums, n, 0, n-1);
    }
};
