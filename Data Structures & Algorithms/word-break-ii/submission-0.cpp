class Trie {
public:    
    Trie * children[26];
    bool isWordEnd;
    Trie() {
        fill(children, children+26, nullptr); 
        isWordEnd = false;
    }    
};

void insert(const string &word, Trie *node) {
    for(auto ch : word) {
        if(node->children[ch-'a'] == NULL) node->children[ch-'a'] = new Trie();
        node = node->children[ch-'a'];
    }
    node->isWordEnd = true;
}

class Solution {
public:
    vector<string> results;
    void recur(const string &str, const int &n, Trie *root, int index, string sentence) {
        if(index == n) {
            sentence.pop_back();
            results.push_back(sentence);
            return;
        }
        Trie *node = root;
        for(int i = index; i < n; i++) {
            node = node->children[str[i] - 'a'];
            if(node == nullptr) break;
            if(node->isWordEnd) {
                string word = str.substr(index, i - index + 1);
                recur(str, n, root, i + 1, sentence + word + " ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        Trie *node = new Trie();
        for(auto word : wordDict) insert(word, node);
        recur(s, n, node, 0, "");
        return results;
    }
};