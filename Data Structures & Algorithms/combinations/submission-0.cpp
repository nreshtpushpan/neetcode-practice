class Solution {
public:
    vector<vector<int>> results;
    int N,K;
    void recur(vector<int> &cur, int index) {
        if((int)cur.size() == K) {
            results.push_back(cur);
            return;
        }
        for(int i = index; i <= N; i++) {
            cur.push_back(i);
            recur(cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        vector<int> cur;
        recur(cur, 1);
        return results;
    }
};