class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int diff = sum - k;
            ans += prefixSum[diff];
            prefixSum[sum]++;
        }
        return ans;
    }
};