class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        int r = n;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == val) swap(nums[--r], nums[i]);
        }
        return r;
    }
};