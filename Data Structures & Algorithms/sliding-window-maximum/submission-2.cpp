class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if(n == 0) return {};
        vector<int> output(n - k + 1);
        deque<int> dq;
        int l = 0, r = 0;
        while(r < n) {
            while(!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if(l > dq.front()) dq.pop_front();
            if(r + 1 >= k) {
                output[l++] = nums[dq.front()];
            }
            ++r;
        }
        return output;
    }
};
