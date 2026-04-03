class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> prod(n, 1);
        int p = 1;
        for(int i = 1 ; i < n; i++) {
            p = p * nums[i-1];
            prod[i] = p;
        }
        p = 1;
        for(int i = n-2 ; i >= 0; i--) {
            p = p * nums[i+1];
            prod[i] *= p;
        }
        return prod;
    }
};
