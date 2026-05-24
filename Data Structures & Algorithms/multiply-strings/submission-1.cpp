class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = (int)num1.size();
        int m = (int)num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> num(n+m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                num[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        // propagate carries
        for(int i = 0; i < n+m-1; i++) {
            num[i+1] += num[i]/10;
            num[i] %= 10;
        }
        reverse(num.begin(), num.end());
        string result = "";
        for(auto dig : num) result += char(dig + '0');
        // remove leading zeros
        int i = 0;
        while(i < (int)result.size()-1 && result[i] == '0') i++;
        return result.substr(i);
    }
};