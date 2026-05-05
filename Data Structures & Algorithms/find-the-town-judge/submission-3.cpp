class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n+1, 0), outDeg(n+1, 0);
        for(auto edge : trust) {
            outDeg[edge[0]]++;
            inDeg[edge[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(inDeg[i] == n-1 && outDeg[i] == 0) return i;
        }
        return -1;
    }
};