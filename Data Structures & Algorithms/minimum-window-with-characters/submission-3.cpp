class Solution {
public:
    string minWindow(string s, string t) {\
        int n = (int)s.size();
        int m = (int)t.size();
        vector<int> req(256, 0);
        for(auto ch: t) req[ch]++;
        int l = 0, minL = n+1;
        int count = 0;
        int start = -1;
        for(int i = 0; i < n; i++) {
            if(req[s[i]] > 0) ++count;
            --req[s[i]];
            while(count == m) {
                if(i - l + 1 < minL) {
                    minL = i - l + 1;
                    start = l;
                }
                ++req[s[l]];
                if(req[s[l]] > 0) --count;
                ++l;
            }
        }
        if(start == -1) return "";
        return s.substr(start, minL);
    }
};
