class Solution {
public:
    void recur(vector<vector<char>>& board, const int &r, const int &c, int i, int j) {
        if(i < 0 || i == r || j < 0 || j == c || board[i][j] != 'O') return;
        board[i][j] = 'S';
        recur(board, r, c, i+1, j);
        recur(board, r, c, i, j+1);
        recur(board, r, c, i-1, j);
        recur(board, r, c, i, j-1);
    }
    void solve(vector<vector<char>>& board) {
        int r = (int)board.size();
        int c = (int)board[0].size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'O' && (i == 0 || i == r-1 || j == 0 || j == c-1)) recur(board, r, c, i, j);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }

    }
};
