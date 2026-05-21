class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = (int)equations.size();
        unordered_map<string, vector<pair<string, double>>> g;
        for(int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            g[u].push_back({v, values[i]});
            g[v].push_back({u, 1.0/values[i]});
        }
        vector<double> results;
        int m = (int)queries.size();
        for(int i = 0; i < m; i++) {
            string start = queries[i][0];
            string end = queries[i][1];
            if(g.find(start) == g.end()) {
                results.push_back((double)-1.0);
                continue;
            }
            if(start == end) {
                results.push_back((double)1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_map<string, bool> vis;
            q.push({start, (double)1.0});
            double cost = -1.0;
            while(!q.empty()) {
                auto [node, curCost] = q.front();
                q.pop();
                if(node == end) {
                    cost = curCost;
                    break;
                }
                if(vis[node]) continue;
                vis[node] = true;
                for(auto child : g[node]) {
                    if(vis[child.first]) continue;
                    q.push({child.first, child.second * curCost});
                }
            }
            results.push_back(cost);
        }
        return results;
    }
};