class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto ch : tasks) freq[ch-'A']++;
        map<int, int> maxFreqCountMap;
        for(int i = 0; i < 26; i++) maxFreqCountMap[freq[i]]++;
        int maxFreq = maxFreqCountMap.rbegin()->first;
        int maxFreqCount = maxFreqCountMap.rbegin()->second;
        return max((int)tasks.size(),  (maxFreq-1) * (n + 1) + maxFreqCount);
    }
};
