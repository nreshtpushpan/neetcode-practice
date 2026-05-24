class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        int n = (int)str1.size();
        int m = (int)str2.size();
        return str1.substr(0, __gcd(n, m));
    }
};