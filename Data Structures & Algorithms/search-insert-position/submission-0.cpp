class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int l = 0, r = n-1, lb = -1;
        while(l <= r) {
            int m = (r - l)/2 + l;
            if(nums[m] == target) return m;
            if(nums[m] < target) {
                lb = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return (lb == -1) ? 0 : lb + 1;
    }
};