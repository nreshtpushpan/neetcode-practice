class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = (int)matrix.size();
        int c = (int)matrix[0].size();
        sumMat.resize(r+1, vector<int> (c+1, 0));
        for(int i = 0; i < r; i++) {
            int prefix = 0;
            for(int j = 0; j < c; j++) {
                prefix += matrix[i][j];
                int above = sumMat[i][j+1];
                sumMat[i+1][j+1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = sumMat[row2+1][col2+1];
        int above = sumMat[row1][col2+1];
        int left = sumMat[row2+1][col1];
        int top = sumMat[row1][col1];
        return bottomRight - above - left + top;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */