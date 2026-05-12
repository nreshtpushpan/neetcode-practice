class Solution {
public:
    void bfsTopologicalSort(const vector<vector<int>> &g, const int &k, vector<int> &inDegree, unordered_map<int, int> &orderMap) {
        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        if(q.empty()) return;
        int i = 0;
        while(!q.empty()) {
            auto val = q.front();
            q.pop();
            //cout<<val<<endl;
            orderMap[val] = i++;
            for(auto child : g[val]) {
                if(--inDegree[child] == 0) q.push(child);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> inDegree(k+1, 0);
        vector<vector<int>> g(k+1);
        for(auto node : rowConditions) {
            g[node[0]].push_back(node[1]);
            inDegree[node[1]]++;
        }
        unordered_map<int, int> rowOrder;
        bfsTopologicalSort(g, k, inDegree, rowOrder);
        if(rowOrder.size() != k) return {};

        g.assign(k+1, {});
        inDegree.assign(k+1, 0);
        for(auto node : colConditions) {
            g[node[0]].push_back(node[1]);
            inDegree[node[1]]++;
        }
        unordered_map<int, int> colOrder;
        bfsTopologicalSort(g, k, inDegree, colOrder);
        if(colOrder.size() != k) return {};

        vector<vector<int>> res(k, vector<int> (k, 0));
        for(int i = 1; i <= k; i++) {
            res[rowOrder[i]][colOrder[i]] = i;
        }

        return res;
    }
};