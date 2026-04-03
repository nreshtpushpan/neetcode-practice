class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int l = 0, r = n-1, ub = n;
        while(l <= r) {
            int m = (r - l)/2 + l;
            if(nums[m] == target) return m;
            if(nums[m] > target) {
                ub = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};