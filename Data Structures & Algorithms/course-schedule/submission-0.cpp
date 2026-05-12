class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for(auto edge : prerequisites) {
            g[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            auto course = q.front();
            q.pop();
            --numCourses;
            for(auto nextCourse: g[course]) {
                if(--inDegree[nextCourse] == 0) q.push(nextCourse);
            }
        }
        return (numCourses == 0);
    }
};
