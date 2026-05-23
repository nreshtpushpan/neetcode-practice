class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        int curEnd = 0, fartestEnd = 0, jumps = 0;
        for(int i = 0; i+1 < n; i++) {
            fartestEnd = max(fartestEnd, i + nums[i]);
            if(i == curEnd) {
                curEnd = fartestEnd;
                ++jumps;
            }
        }
        return jumps;
    }
};
