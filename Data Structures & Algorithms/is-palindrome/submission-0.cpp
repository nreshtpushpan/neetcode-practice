class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n = (int)s.size();
        int l = 0, r = n-1;
        while(l <= r) {
            while(l < n && !isalnum(s[l])) {
                ++l;
            }
            while(r >= 0 && !isalnum(s[r])) {
                --r;
            }
            if(l > r) return true;
            if(toupper(s[l]) != toupper(s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
};
