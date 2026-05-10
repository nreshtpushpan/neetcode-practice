class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxL = 1;
    
        auto expand = [&](int l, int r) {
            while(l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
            if(r - l - 1 > maxL) {
                maxL = r - l - 1;
                start = l + 1;
            }
        };

        for(int i = 0; i < n; i++) {
            expand(i, i);    // odd length
            expand(i, i+1);  // even length
        }
        return s.substr(start, maxL);
    }
};
