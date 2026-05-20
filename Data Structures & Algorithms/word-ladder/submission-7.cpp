class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());
        int len = 1;
        queue<string> q;
        q.push({beginWord, 0});
        while(!q.empty()) {
            int siz = q.size();
            for(int k = 0; k < siz; k++) {
                auto word = q.front();
                q.pop();
                if(word == endWord) return len;
                int m = (int)word.size();
                for(int i = 0; i < m; i++) {
                    int ch = word[i];
                    for(char changeCh = 'a'; changeCh <= 'z'; changeCh++) {
                        word[i] = changeCh;
                        auto it = dic.find(word);
                        if(it == dic.end()) continue;
                        q.push(word);
                        dic.erase(it);
                    }
                    word[i] = ch;
                }
            }
            ++len;
        }
        return 0;
    }
};
