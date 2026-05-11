class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> dead;
        for(auto invalid: deadends) dead.insert(stoi(invalid));
        if(dead.find(0) != dead.end()) return -1;
        int mod = 10000;
        vector<bool> vis(mod, false);
        int level = 0;
        int targetNum = stoi(target);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int siz = q.size();
            for(int i = 0; i < siz; i++) {
                auto num = q.front();
                q.pop();
                if(num == targetNum) return level;
                for(int j = 0; j < 4; j++) {
                    int diff = 1;
                    for(int k = 0; k < j && k < 4; k++) diff *= 10;
                    int digit = (num / diff) % 10;
    
                    int up   = num + (((digit + 1) % 10) - digit) * diff;
                    int down = num + (((digit - 1 + 10) % 10) - digit) * diff;
    
                    if(!vis[up]   && !dead.count(up))   { vis[up]=true;   q.push(up);   }
                    if(!vis[down] && !dead.count(down)) { vis[down]=true; q.push(down); }
                }
            }
            ++level;
        }
        
        return -1;
    }
};