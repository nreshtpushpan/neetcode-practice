class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = (int)s.size();
        string str = "";
        for(int i = 0; i < n;) {
            if(s[i] == '#') {
                int len = stoi(str);
                result.push_back(s.substr(i+1, len));
                i = i+1+len;
                str = "";
                continue;
            } 
            str += s[i];
            ++i;
        }
        return result;
    }
};
