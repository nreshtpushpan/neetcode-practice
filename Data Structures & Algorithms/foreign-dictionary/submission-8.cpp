class Solution {
public:
    bool isCycle(unordered_map<char, vector<char>> &g, char curChar, unordered_map<char, bool> &vis, string &order) {
        if(vis.count(curChar)) return vis[curChar];
        vis[curChar] = true;
        for(auto childCh : g[curChar]) {
            if(isCycle(g, childCh, vis, order)) return true;
        }
        order.push_back(curChar);
        vis[curChar] = false;
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        int n = (int)words.size();
        unordered_map<char, vector<char>> g;
        for(const auto &word: words) {
            for(char ch : word) g[ch];
        }
        for(int i = 1; i < n; i++) {
            auto prevW = words[i-1];
            auto word = words[i];
            int n = (int)prevW.size();
            int m = (int)word.size();
            if(n > m && prevW.substr(0, m) == word) return "";
            for(int j = 0; j < min(n, m); j++) {
                if(prevW[j] != word[j]) {
                    g[prevW[j]].push_back(word[j]);
                    break;
                }
            }
        }
        unordered_map<char, bool> vis;
        string order = "";
        for(auto it : g) if(isCycle(g, it.first, vis, order)) return "";
        reverse(order.begin(), order.end());
        return order;
    }
};
