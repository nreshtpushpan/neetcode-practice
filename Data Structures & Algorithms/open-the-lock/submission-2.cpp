class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto invalid: deadends) dead.insert(invalid);
        if(dead.find("0000") != dead.end()) return -1;
        int mod = 10000;
        vector<bool> vis(mod, false);
        int level = 0;
        queue<string> q;
        q.push("0000");
        vis[0] = true;
        while(!q.empty()) {
            int siz = q.size();
            for(int i = 0; i < siz; i++) {
                auto num = q.front();
                q.pop();
                if(num == target) return level;
                for(int j = 0; j < 4; j++) {
                    string upStr = num;
                    upStr[j] = ((num[j] - '0' + 1)%10 + '0');
                    string downStr = num;
                    downStr[j] = ((num[j] - '0' - 1 + 10)%10 + '0');
                    if(!vis[stoi(upStr)]   && !dead.count(upStr))   { vis[stoi(upStr)]=true;   q.push(upStr);   }
                    if(!vis[stoi(downStr)] && !dead.count(downStr)) { vis[stoi(downStr)]=true; q.push(downStr); }
                }
            }
            ++level;
        }
        
        return -1;
    }
};