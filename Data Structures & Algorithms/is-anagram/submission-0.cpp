class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if(n != m) return false;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(auto count: freq) if(count) return false;
        return true;
        
    }
};
