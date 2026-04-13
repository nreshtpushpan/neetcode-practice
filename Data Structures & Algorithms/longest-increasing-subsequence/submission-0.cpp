class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> tail;
        for(auto num: nums) {
            auto it = lower_bound(tail.begin(), tail.end(), num);
            if(it == tail.end()) {
                tail.push_back(num);
                continue;
            }
            int index = it - tail.begin();
            tail[index] = num;
        }
        return tail.size();
    }
};
