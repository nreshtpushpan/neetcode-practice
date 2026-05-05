class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        string res = "";
        while(!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            if(res.size() > 1 && res.back() == ch && res[res.size() - 2] == ch) {
                if(pq.empty()) return res;
                auto [count2, ch2] = pq.top();
                pq.pop();
                res += ch2;
                if(--count2) pq.push({count2, ch2});
                pq.push({count, ch});
            } else {
                res += ch;
                if(--count) pq.push({count, ch});
            }
        }
        return res;
    }
};