class Solution {
public:
    vector<vector<int>> dp;
    int res = 0;
    void calMax(const vector<int> &nums, const int &s, const int &e) {
        for(int i = s; i <= e; i++) {
            dp[i][0] = (i > s) ? nums[i] + dp[i-1][1] : nums[s];
            dp[i][1] = (i > s) ? max(dp[i-1][0], dp[i-1][1]) : 0;
            res = max({res, dp[i][0], dp[i][1]});
        }
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return nums[0];
        dp.resize(n, vector<int> (2, 0));
        calMax(nums, 0, n-2);
        dp.assign(n, vector<int> (2, 0));
        calMax(nums, 1, n-1);
        return res;
    }
};
