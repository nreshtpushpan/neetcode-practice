class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dic;
        int n = (int)wordList.size();
        for(int i = 0; i < n; i++) dic[wordList[i]] = i;
        int len = 1;
        queue<pair<string, bitset<100>>> q;
        q.push({beginWord, 0});
        while(!q.empty()) {
            int siz = q.size();
            for(int k = 0; k < siz; k++) {
                auto [word, hash] = q.front();
                q.pop();
                if(word == endWord) return len;
                int m = (int)word.size();
                for(int i = 0; i < m; i++) {
                    int ch = word[i];
                    for(char changeCh = 'a'; changeCh <= 'z'; changeCh++) {
                        word[i] = changeCh;
                        auto it = dic.find(word);
                        if(it == dic.end()) continue;
                        int index = it->second;
                        if(hash.test(index)) continue;
                        hash.set(index);
                        q.push({word, hash});
                        //hash.reset(index);
                    }
                    word[i] = ch;
                }
            }
            ++len;
        }
        return 0;
    }
};
