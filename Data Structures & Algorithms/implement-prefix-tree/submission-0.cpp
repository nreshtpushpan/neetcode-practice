class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
};
class PrefixTree {
public:
    TrieNode *root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(auto ch: word) {
            if(cur->children.find(ch) == cur->children.end()) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto ch: word) {
            if(cur->children.find(ch) == cur->children.end()) return false;
            cur = cur->children[ch];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto ch: prefix) {
            if(cur->children.find(ch) == cur->children.end()) return false;
            cur = cur->children[ch];
        }
        return true;
    }
};
