class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        int curMax = 1, curMin = 1;
        int n = (int)nums.size();
        for(auto num : nums) {
           int oldMax = curMax;
           curMax = max({num, curMax * num, curMin * num});
           curMin = min({num, curMin * num, oldMax * num});
           maxP = max({maxP, curMax, curMin});
        }
        return maxP;
    }
};
