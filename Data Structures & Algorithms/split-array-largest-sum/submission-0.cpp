class Solution {
public:
    int totalSplits(const vector<int> &nums, int maxSum) {
        int curSum = 0;
        int splits = 1;
        for(auto num : nums) {
            if(curSum + num > maxSum) {
                ++splits;
                curSum = num;
            } else {
                curSum += num;
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int maxSum = 0, maxIndSum = 0;
        for(auto num : nums) {
            maxSum += num;
            maxIndSum = max(maxIndSum , num);
        }
        int l = maxIndSum, r = maxSum;
        int res = maxSum;
        while(l <= r) {
            int m = (r - l)/2 + l;
            int splitsRquired = totalSplits(nums, m);
            if (splitsRquired <= k) {
                r = m-1;
                res = m;
            } else {
                l = m+1;
            }
        }
        return res;
    }
};