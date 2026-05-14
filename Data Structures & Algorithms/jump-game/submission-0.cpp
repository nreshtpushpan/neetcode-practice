class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        int maxRange = 0;
        for(int i = 0; i < n; i++) {
            if(i > maxRange) return false;
            maxRange = max(maxRange, i + nums[i]);
        }
        return true;
    }
};
