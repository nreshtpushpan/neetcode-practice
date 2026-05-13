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
        unordered_map<string, int> emailToAcc;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    merge(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }
        // Group emails by leader account
        map<int, vector<string>> emailGroup; // index of acc -> list of emails
        for (const auto& [email, accId] : emailToAcc) {
            int leader = findP(accId);
            emailGroup[leader].push_back(email);
        }
        // Build result
        vector<vector<string>> res;
        for (auto& [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }
        
        return res;
    }
};