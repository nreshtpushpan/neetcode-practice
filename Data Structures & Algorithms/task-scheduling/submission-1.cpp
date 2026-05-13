class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto ch : tasks) freq[ch-'A']++;
        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxFreqCount = 0;
        for(auto count : freq) maxFreqCount += (count == maxFreq);
        return max((int)tasks.size(),  (maxFreq-1) * (n + 1) + maxFreqCount);
    }
};
