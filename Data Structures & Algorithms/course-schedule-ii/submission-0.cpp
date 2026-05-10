class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for(auto edge : prerequisites) {
            g[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            auto course = q.front();
            q.pop();
            res.push_back(course);
            for(auto dependentCourse : g[course]) {
                if(--inDegree[dependentCourse] == 0) q.push(dependentCourse);
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
