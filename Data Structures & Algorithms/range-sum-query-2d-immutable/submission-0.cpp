class NumMatrix {
public:
    vector<vector<int>> rowSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = (int)matrix.size();
        int c = (int)matrix[0].size();
        rowSum.resize(r, vector<int> (c, 0));
        for(int i = 0; i < r; i++) rowSum[i][0] = matrix[i][0];
        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                rowSum[i][j] = matrix[i][j] + rowSum[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            sum += rowSum[i][col2];
            sum -= (col1 > 0) ? rowSum[i][col1-1] : 0;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */