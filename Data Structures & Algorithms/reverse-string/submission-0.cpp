class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        int  n = (int)s.size();
        for(int i = 0; i < n/2; i++) {
            char tmp = s[i];
            char swapTmp = s[n-1-i];
            s[n-1-i] = tmp;
            s[i] = swapTmp;
        }
        
    }
};