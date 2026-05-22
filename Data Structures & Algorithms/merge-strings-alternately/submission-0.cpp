class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n = (int)w1.size();
        int m = (int)w2.size();
        string results = "";
        int i = 0, j = 0;
        while(i < n && j < m) {
            results += w1[i++];
            results += w2[j++];
        }
        while(i < n) results += w1[i++];
        while(j < m) results += w2[j++];
        return results;
    }
};