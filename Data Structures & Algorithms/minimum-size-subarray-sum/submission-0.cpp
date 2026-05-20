class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int minLen = n+1;
        int curSum = 0, start = 0;
        for(int end = 0; end < n; end++) {
            curSum += nums[end];
            while(curSum >= target && start <= end) {
                minLen = min(minLen, end - start + 1);
                curSum -= nums[start++];
            }
        }
        return (minLen == n+1) ? 0 : minLen;
    }
};