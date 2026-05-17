class Solution {
public:
    map<pair<int,int>, int> dp;
    int recur(const vector<int>& nums, const int &n, int index, int target) {
        if(index == n) return target == 0;
        if(dp.count({index, target})) return dp[{index, target}];
        int result = 0;
        result += recur(nums, n, index + 1, target + nums[index]);
        result += recur(nums, n, index + 1, target - nums[index]);
        return dp[{index, target}] = result;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        return recur(nums, n, 0, target);
    }
};
