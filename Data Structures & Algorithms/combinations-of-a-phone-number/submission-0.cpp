class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string str = "";
        queue<pair<string, int>> q;
        int n = (int)digits.size();
        q.push({"", 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            string curStr = p.first;
            int index = p.second;
            if(index == n) {
                ans.push_back(curStr);
                continue;
            }
            for(auto ch: mp[digits[index]]) {
                q.push({curStr + ch, index + 1});
            }
        }
    
        return ans;

    }
};
