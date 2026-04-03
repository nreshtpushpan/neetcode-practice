class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto it : mp) {
            freq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = n; i >= 0; i--) {
            if(freq[i].empty()) continue;
            for(auto num : freq[i]) {
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
