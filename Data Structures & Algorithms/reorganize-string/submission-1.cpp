class Solution {
public:
    
    string reorganizeString(string s) {
        int n = (int)s.size();
        unordered_map<char, int> mp;
        for(auto ch : s) mp[ch]++;
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) pq.push({it.second, it.first});
        string str = "";
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
           // cout<<t.first<<" "<<t.second<<endl;
            if(str.empty() || str.back() != t.second) {
                str += t.second;
               // cout<<t.second<<" ";
                if(--t.first) pq.push({t.first, t.second});
            } else {
                if(pq.empty()) return "";
                auto t2 = pq.top();
                pq.pop();
                str += t2.second;
                //cout<<t2.second<<" ";
                if(--t2.first)pq.push({t2.first, t2.second});
                pq.push(t);
            }
        }
        return str;
    }
};