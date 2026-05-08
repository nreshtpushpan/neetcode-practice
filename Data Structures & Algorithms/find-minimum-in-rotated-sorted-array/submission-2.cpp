class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = (int)nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            int m = l + (r-l)/2;
            if(nums[m] > nums[m+1]) return nums[m+1];
            if(nums[m] < nums[m-1]) return nums[m];
            if(nums[l] < nums[m]) {
                l = m + 1;
            } else {
                if(nums[m] > nums[l]) l = m+1;
                else r = m-1;
            }
        }
        return nums[0];
    }
};
