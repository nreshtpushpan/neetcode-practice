class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string cur = "";
        string charNum = "";
        for(auto ch : s) {
            if(ch  >= '0' && ch <= '9') {
                charNum += ch;
            } else if(ch == '[') {
                st.push({cur, stoi(charNum)});
                cur = "";
                charNum = "";
            } else if(ch == ']') {
                int freq = st.empty() ? 0 : st.top().second;
                string repeatedCur = "";
                for(int i = 0; i < freq; i++)repeatedCur += cur;
                cur = (st.empty() ? "" : st.top().first) + repeatedCur;
                st.pop();
            } else {
                cur += ch;
            }
        }

        return cur;
    }
};