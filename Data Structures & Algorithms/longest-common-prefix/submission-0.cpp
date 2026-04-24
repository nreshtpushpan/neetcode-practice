class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
    }

    int lcp(const string& word, int prefixLen) {
        TrieNode* node = root;
        int i = 0;
        while (i < min((int)word.length(), prefixLen)) {
            if (node->children.find(word[i]) == node->children.end()) {
                return i;
            }
            node = node->children[word[i]];
            i++;
        }
        return min((int)word.length(), prefixLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        int mini = 0;
        for (int i = 1; i < strs.size(); i++) {
            if (strs[mini].size() > strs[i].size()) {
                mini = i;
            }
        }

        Trie trie;
        trie.insert(strs[mini]);
        int prefixLen = strs[mini].length();

        for (int i = 0; i < strs.size(); i++) {
            prefixLen = trie.lcp(strs[i], prefixLen);
        }

        return strs[0].substr(0, prefixLen);
    }
};