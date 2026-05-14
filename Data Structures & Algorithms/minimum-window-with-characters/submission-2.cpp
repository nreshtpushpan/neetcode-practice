class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for(auto ch: t) freq[ch]++;
        int m = (int)t.size();
        int n = (int)s.size();
        int minLen = INT_MAX;
        int l = 0, r = 0, start = 0;
        int count = 0;
        while(l <= r && r < n) {
            if(freq[s[r]] > 0) ++count;
            --freq[s[r]];
            while(count == m) {
                if(minLen > r - l + 1) {
                    minLen = r - l + 1;
                    start = l;
                }
                ++freq[s[l]];
                if(freq[s[l]] > 0) --count;
                ++l;
            }
            ++r;
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
