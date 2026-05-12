class Trie {
public:    
    Trie* children[26];
    bool isCompleteWord;
    string word;
    Trie() {
        isCompleteWord = false;
        word = "";
        fill(children, children+26, nullptr); 
    }
};
class Solution {
public:
    vector<string> result;
    void recur(const vector<vector<char>> &g, const int &r, const int &c, Trie *node, vector<vector<bool>> &vis, int a, int b) {
        if(node == NULL) return;
        if(node->isCompleteWord) {
            result.push_back(node->word);
            node->isCompleteWord = false;
            node->word = "";
        }
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i*i + j*j != 1) continue;
                int ii = i + a;
                int jj = j + b;
                if(ii < 0 || ii == r || jj < 0 || jj == c) continue;
                if(node->children[g[ii][jj]-'a'] == NULL) continue;
                if(vis[ii][jj]) continue;
                vis[ii][jj] = true;
                recur(g, r, c, node->children[g[ii][jj]-'a'], vis, ii, jj);
                vis[ii][jj] = false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie * trieNode = new Trie();
        for(auto word : words) {
            Trie * cur = trieNode;
            for(auto ch : word) {
                if(cur->children[ch-'a'] == NULL) cur->children[ch-'a'] = new Trie();
                cur = cur->children[ch-'a'];
            }
            cur->isCompleteWord = true;
            cur->word = word;
        }
        int r = (int)board.size();
        int c = (int)board[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                vis[i][j] = true;
                recur(board, r, c, trieNode->children[board[i][j]-'a'], vis, i, j);
                vis[i][j] = false;
            }
        }
        return result;
    }
};
