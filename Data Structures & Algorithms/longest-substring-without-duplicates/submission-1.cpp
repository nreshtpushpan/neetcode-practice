class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        if(n == 0) return n;
        vector<int> freq(256, 0);
        int start = 0, end = 0, maxL = 1;
        for( ; end < n; end++) {
            ++freq[s[end]];
            while(freq[s[end]] != 1) --freq[s[start++]];
            maxL = max(maxL, end - start + 1);
        }
        return maxL;
    }
};
