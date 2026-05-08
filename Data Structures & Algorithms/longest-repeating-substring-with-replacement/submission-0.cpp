class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int)s.size();
        int l = 0, maxFreq = 1, maxL = 1;
        unordered_map<char, int> freq;
        for(int r = 0; r < n; r++) {
            maxFreq = max(maxFreq, ++freq[s[r]]);
            while(r - l + 1 - maxFreq > k) {
                freq[s[l++]]--;
            }
            maxL = max(maxL, r - l + 1);
        }
        return maxL;
    }
};
