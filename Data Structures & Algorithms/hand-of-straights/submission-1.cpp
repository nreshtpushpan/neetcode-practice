class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();
        if(n%groupSize) return false;
        vector<int> freq(1001, 0);
        int maxNum = 0;
        for(auto num : hand) {
            freq[num]++;
            maxNum = max(maxNum, num);
        }
        for(int i = 0; i <= maxNum; i++) {
            if(freq[i] == 0) continue;
            int count = freq[i];
            for(int j = 0; j < groupSize; j++) {
                if(i+j > maxNum || freq[i+j] < count) return false;
                freq[i+j] -= count;
            }
        }
        return true;
    }
};
