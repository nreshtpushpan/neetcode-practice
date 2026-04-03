class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = (int)nums.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;
            if(nums[m] > target) {
                r = m-1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
