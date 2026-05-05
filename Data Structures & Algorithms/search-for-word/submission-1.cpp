class Solution {
public:
    int n,r,c;
    vector<vector<bool>> visit;
    bool recur(vector<vector<char>>& board, const string word, int rr, int cc, int index) {
        if(index == n) return true;
        visit[rr][cc] = true;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i*i + j*j != 1) continue;
                int ii = i + rr;
                int jj = j + cc;
                if(ii < 0 || ii == r || jj < 0 || jj == c) continue;
                if(board[ii][jj] != word[index] || visit[ii][jj]) continue;
                if(recur(board, word, ii, jj, index+1)) return true;
            }
        }
        visit[rr][cc] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = (int)word.size();
        r = (int)board.size();
        c = (int)board[0].size();
        visit.resize(r, vector<bool> (c, false));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == word[0] && recur(board, word, i, j, 1)) return true;
            }
        }
        return false;
    }
};
