class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), grid(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                auto rowF = row[i].find(num);
                if(rowF != row[i].end()) return false;
                row[i].insert(num);
                auto colF = col[j].find(num);
                if(colF != col[j].end()) return false;
                col[j].insert(num);
                int index = (i/3)*3 + (j/3);
                auto gridF = grid[index].find(num);
                if(gridF != grid[index].end()) return false;
                grid[index].insert(num);
            }
        }
        return true;
    }
};
