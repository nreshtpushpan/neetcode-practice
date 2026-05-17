class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(auto ch : s1) freq[ch-'a']++;
        int start = 0, end = 0;
        int n = (int)s2.size(), m = (int)s1.size();
        int req = 0;
        while(start <= end && end < n) {
            if(freq[s2[end] - 'a'] > 0) ++req;
            freq[s2[end] - 'a']--;
            while(req == m) {
                if(end - start + 1 == m) return true;
                if(++freq[s2[start] - 'a'] > 0) --req;
                start++;
            }
            ++end;
        }
        return false;
    }
};
