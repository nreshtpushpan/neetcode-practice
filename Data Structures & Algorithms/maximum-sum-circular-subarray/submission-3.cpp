class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = (int)nums.size();
        int curMax = 0, curMin = 0;
        int globalMax = nums[0], globalMin = nums[0];
        int total = 0;
        for(int i = 0; i < n; i++) {
            curMax = max(nums[i], curMax + nums[i]);
            curMin = min(nums[i], curMin + nums[i]);
            globalMax = max(globalMax, curMax);
            globalMin = min(globalMin, curMin);
            total += nums[i];
        }
        return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;

    }
};