class Solution {
public:
    int calPoints(vector<string>& o) {
        if(o.empty()) return 0;
        vector<int> last;
        for(auto s: o) {
            int siz = last.size();
            if(s == "+") {
                last.push_back(last[siz-1] + last[siz-2]);
            } else if(s == "D") {
                last.push_back(last[siz-1] * 2);
            } else if(s == "C") {
                last.pop_back();
            } else {
                last.push_back(stoi(s));
            }
        }
        return accumulate(last.begin(), last.end(), 0);
    }
};