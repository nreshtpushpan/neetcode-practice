class Solution {
public:
    int result = 0;
    void recur(const vector<int>& nums, const int &n, int index, int target) {
        if(index == n) {
            if(target == 0) ++result;
            return;
        }
        recur(nums, n, index + 1, target + nums[index]);
        recur(nums, n, index + 1, target - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        recur(nums, n, 0, target);
        return result;
    }
};
