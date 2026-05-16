class Solution {
public:
    vector<string> splitStr(const string &str, char delimiter) {
        vector<string> resultStr;
        string cur = "";
        for(auto ch : str) {
            if(ch == delimiter) {
                if(!cur.empty()) {
                    resultStr.push_back(cur);
                }
                cur = "";
                continue;
            }
            cur += ch;
        }
        if(!cur.empty()) resultStr.push_back(cur);
        return resultStr;
    }
    string simplifyPath(string path) {
        vector<string> tokens = splitStr(path, '/');
        stack<string> st;
        for(auto& token : tokens) {
            if(token == "..") {
                if(!st.empty()) st.pop();
            } else if(token != ".") {
                st.push(token);
            }
        }
        string result = "";
        while(!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};