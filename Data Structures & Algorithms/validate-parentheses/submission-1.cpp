class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> st;
        for(auto ch: s) {
            if(ch == '[' || ch == '(' || ch == '{') {
                st.push(ch);
                continue;
            }
            if(ch == ']' and !st.empty() && st.top() == '[') st.pop();
            else if(ch == ')' and !st.empty() && st.top() == '(') st.pop();
            else if(ch == '}' and !st.empty() && st.top() == '{') st.pop();
            else return false;
        }
        return st.empty();
    }
};
