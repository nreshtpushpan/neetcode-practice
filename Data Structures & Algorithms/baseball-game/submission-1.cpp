class Solution {
public:
    int calPoints(vector<string>& o) {
        if(o.empty()) return 0;
        vector<int> last;
        int ans = 0;
        for(auto s: o) {
            if(s == "+") {
                int t = last.back();
                last.pop_back();
                int lt = last.back();
                last.pop_back();
                ans += t + lt;
                last.push_back(t);
                last.push_back(t + lt);
            } else if(s == "D") {
                int t = last.back();
                ans += t * 2;
                last.push_back(t * 2);
            } else if(s == "C") {
                int t = last.back();
                ans -= t;
                last.pop_back();
            } else {
                int num = stoi(s);
                ans += num;
                last.push_back(num);
            }
        }
        return ans;
    }
};