class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int)strs.size();
        if(n == 0) return {{}};
        map<vector<int> , int> dic;
        vector<vector<string>> ans;
        for(auto str: strs) {
            vector<int> count(26, 0);
            for(auto ch: str) {
                count[ch - 'a']++;
            }
            int index;
            auto it = dic.find(count);
            if(it == dic.end()) {
                dic[count] = ans.size();
                ans.push_back({str});
                continue;
            }
            ans[it->second].push_back(str);
        }
        return ans;
    }
};
