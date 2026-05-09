class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return nums[0];
        int freq = 1, majNum = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] == majNum) {
                ++freq;
                continue;
            }
            if(--freq == 0) {
                freq = 1;
                majNum = nums[i];
            }
        }
        return majNum;
    }
};