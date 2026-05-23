class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        int curP = 1;
        int n = (int)nums.size();
        for(auto num : nums) {
            curP *= num;
            maxP = max(maxP, curP);
            if(curP == 0) curP = 1;
        }
        curP = 1;
        for(int i = n-1; i >= 0; i--) {
            curP *= nums[i];
            maxP = max(maxP, curP);
            if(curP == 0) curP = 1;
        }
        return maxP;
    }
};
