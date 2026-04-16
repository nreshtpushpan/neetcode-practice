class Solution {
public:
    bool dfs(unordered_map<char, unordered_set<char>> &g, unordered_map<char, bool> &visit, string &result, char node) {
        if(visit.find(node) != visit.end()) return visit[node];
        visit[node] = true;
        for(char child: g[node]) {
            if(dfs(g, visit, result, child)) return true;
        }
        visit[node] = false;
        result.push_back(node);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> g;
        unordered_map<char, bool> visit;
        int n = (int)words.size();
        for (const auto& word : words) {
            for (char ch : word) {
                g[ch];
            }
        }
        for(int i = 0; i + 1 < n; i++) {
            string w1 = words[i], w2 = words[i+1];
            int minL = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.substr(0, minL) == w2) return "";
            for(int j = 0; j < minL; j++) {
                if(w1[j] != w2[j]) {
                    g[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        string result;
        for(auto it : g) {
            if(dfs(g, visit, result, it.first)) return "";
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};
