class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int balance = 0;
        unordered_map<int, int> mp;
        for(auto num : bills) {
            switch (num) {
                case 5 : {
                    mp[num]++;
                    break;
                };
                case 10 : {
                    if(mp[5] == 0) return false;
                    mp[5]--;
                    mp[10]++;
                    break;
                };
                default : {
                    if(mp[5] == 0) return false;
                    if(mp[10] == 0 && mp[5] < 3) return false;
                    if(mp[10]) {
                        mp[10]--;
                        mp[5]--;
                    } else {
                        mp[5] -= 3;
                    }
                    mp[20]++;
                }
            }
        }
        return true;
    }
};