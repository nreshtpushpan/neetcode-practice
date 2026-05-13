class Solution {
public:
    vector<int> parent, rank;
    int findP(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findP(parent[node]);
    }
    void merge(int a, int b) {
        int pa = findP(a);
        int pb = findP(b);
        if(pa == pb) return;
        if(rank[pa] < rank[pb]) {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        } else {
            parent[pb] = pa;
            rank[pb] += rank[pa];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = (int)accounts.size();
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        unordered_map<string, int> mp;
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < accounts[i].size(); j++) {
                if(j == 0) continue;
                auto it = mp.find(accounts[i][j]);
                if(it == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    merge(mp[accounts[i][j]], i);
                }
            }
        }
        unordered_map<int, set<string>> resultSet;
        for(int i = 0; i < n; i++) {
            int parentI = findP(i);
            for(int j = 0; j < accounts[i].size(); j++) {
                if(j == 0) continue;
                resultSet[parentI].insert(accounts[i][j]);          
            }
        }
        vector<vector<string>> results;
        for(auto [index, setResult] : resultSet) {
            vector<string> res;
            res.push_back(accounts[index][0]);
            for(auto email : setResult) res.push_back(email);
            results.push_back(res);
        }
        
        return results;
    }
};