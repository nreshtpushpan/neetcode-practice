class Trie {
public:    
    Trie *child[26];
    bool isWord;
    Trie() {
        fill(child, child + 26, nullptr);
        isWord = false;
    }
};
class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = root;
        for(auto ch : word) {
            if(cur->child[ch-'a'] == nullptr) cur->child[ch-'a'] = new Trie();
            cur = cur->child[ch-'a'];
        }
        cur->isWord = true;
    }
    
    bool findWord(const string &word, Trie* cur, int index) {
        if(cur == nullptr) return false;
        if(index == (int)word.size()) return cur->isWord;
        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                if(cur->child[i] == nullptr) continue;
                if(findWord(word, cur->child[i], index+1)) return true;
            }
            return false;
        }
        if(cur->child[word[index] - 'a'] == nullptr) return false;
        return findWord(word, cur->child[word[index] - 'a'], index+1);
    }
    bool search(string word) {
        Trie *cur = root;
        return findWord(word, cur, 0);
    }
};
