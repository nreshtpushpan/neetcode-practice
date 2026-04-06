class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if(n == 0) return {};
        map<int, int> freq;
        vector<int> ans;
        for(int i = 0; i < k; i++) freq[nums[i]]++;
        auto it = freq.rbegin();
        ans.push_back((*it).first);
        for(int i = k; i < n; i++) {
            freq[nums[i]]++;
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0) freq.erase(freq.find(nums[i-k]));
            auto it = freq.rbegin();
            ans.push_back((*it).first);
        }
        return ans;
    }
};
