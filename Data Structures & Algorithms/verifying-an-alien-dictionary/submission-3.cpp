class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> indexMap (26, - 1);
        int m = (int)order.size();
        for(int i = 0; i < m; i++) indexMap[order[i]-'a'] = i;
        int n = (int)words.size();
        for(int i = 1; i < n; i++) {
            string prevW = words[i-1];
            string curW = words[i];
            int a = (int)prevW.size();
            int b = (int)curW.size();
            bool orderCanBeFound = false;
            for(int j = 0; j < min(a, b); j++) {
                char prevCh = prevW[j];
                char curCh = curW[j];
                if(prevCh != curCh) {
                    orderCanBeFound = true;
                    if(indexMap[prevCh-'a'] > indexMap[curCh-'a']) return false;
                    break;
                }
            }
            if(!orderCanBeFound && a > b) return false;
        }
        return true;
    }
};