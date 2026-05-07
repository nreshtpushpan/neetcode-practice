class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = (int)people.size()-1;
        int res = 0;
        while(l <= r) {
            int secondLimit = limit - people[r--];
            ++res;
            if(people[l] <= secondLimit) ++l;
        }
        return res;
    }
};