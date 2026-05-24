class Solution {
public:
    int N, ans = 0;
    vector<vector<string>> results;
    vector<int> queenCols;
    vector<string> generateSolution() {
        vector<string> board(N, string(N, '.'));
        for(int row = 0; row < N; row++)
            board[row][queenCols[row]] = 'Q';
        return board;
    }
    void recur(int row, int colHash, int diagHash, int antiDiagHash) {
        if(row == N) { 
            results.push_back(generateSolution());
            return; 
        }
        for(int col = 0; col < N; col++) {
            int diag     = row - col + N;  // offset to keep positive
            int antiDiag = row + col;
            if(colHash & (1 << col))      continue;  // column used
            if(diagHash & (1 << diag))     continue;  // diagonal used
            if(antiDiagHash & (1 << antiDiag)) continue; // anti-diagonal used
            queenCols.push_back(col);
            recur(row+1,
                  colHash      | (1 << col),
                  diagHash     | (1 << diag),
                  antiDiagHash | (1 << antiDiag));
             queenCols.pop_back();    
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        int colHash = 0, diagHash = 0, antiDiagHash = 0;
        recur(0, colHash, diagHash, antiDiagHash);
        return results;
    }
};
