class Solution {
public:
    int N, ans = 0;
   
    void recur(int row, int colHash, int diagHash, int antiDiagHash) {
        if(row == N) { ++ans; return; }
        for(int col = 0; col < N; col++) {
            int diag     = row - col + N;  // offset to keep positive
            int antiDiag = row + col;
            if(colHash     & (1 << col))      continue;  // column used
            if(diagHash    & (1 << diag))     continue;  // diagonal used
            if(antiDiagHash & (1 << antiDiag)) continue; // anti-diagonal used
            recur(row+1,
                  colHash      | (1 << col),
                  diagHash     | (1 << diag),
                  antiDiagHash | (1 << antiDiag));
        }
    }
    int totalNQueens(int n) {
        N = n;
        int colHash = 0, diag = 0, antiDiagHash = 0;
        recur(0, colHash, diag, antiDiagHash);
        return ans;
    }
};