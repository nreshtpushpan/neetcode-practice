class Solution {
public:
    unordered_map<int, int> dp;
    int recur(const int &num, const unordered_set<int> &dic) {
        auto it = dp.find(num);
        if(it != dp.end()) return it->second;
        auto find = dic.find(num);
        if(find == dic.end()) return dp[num] = 0;
        return dp[num] = 1 + recur(num - 1, dic);
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dic(nums.begin(), nums.end());
        int maxL = 0;
        sort(nums.begin(), nums.end());
        for(auto num : nums) {
            maxL = max(maxL, recur(num, dic));
        }
        return maxL;
    }
};
