class Solution {
public:
    bool isCycle(unordered_map<char, vector<char>> &g, unordered_map<char, bool> &vis, string &result, char cur) {
        if(vis.count(cur)) return vis[cur];
        vis[cur] = true;
        for(auto nextCh : g[cur]) {
            if(isCycle(g, vis, result, nextCh)) return true;
        }
        vis[cur] = false;
        result.push_back(cur);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> g;
        unordered_map<char, bool> vis;
        int n = (int)words.size();
        for (const auto& word : words) {
            for (char ch : word) {
                g[ch];
            }
        }
        for(int i = 1; i < n; i++) {
            auto w1 = words[i-1];
            auto w2 = words[i];
            int k = (int)w1.size();
            int l = (int)w2.size();
            if(k > l && w1.substr(0, l) == w2) return ""; 
            for(int j = 0; j < min(k, l); j++) {
                if(w1[j] != w2[j]) {
                    g[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        string result = "";
        for(auto it : g) {
            if(isCycle(g, vis, result, it.first)) return "";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
