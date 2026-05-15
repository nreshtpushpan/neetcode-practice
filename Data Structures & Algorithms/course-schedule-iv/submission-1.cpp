class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> inDegree(numCourses, 0);
        vector<bitset<200>> preReq(numCourses);
        vector<vector<int>> g(numCourses);
        for(auto edge : prerequisites) {
            g[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        //iota(preReq.begin(), preReq.end(), 0);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(auto child : g[node]) {
                if(--inDegree[child] == 0) q.push(child);
                preReq[child] |= preReq[node];
                preReq[child].set(node);
            }
        }
        int m = (int)queries.size();
        vector<bool> result(m);
        for(int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            result[i] = preReq[b].test(a);
        }
        return result;
    }
};