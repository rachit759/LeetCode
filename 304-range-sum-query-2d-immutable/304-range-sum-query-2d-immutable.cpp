class NumMatrix {
public:
    vector<vector<int>> mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        for(int i = 0 ; i< mat.size(); i++) {
            partial_sum(begin(mat[i]),end(mat[i]),begin(mat[i]));
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            if(col1 == 0) {
                sum += mat[i][col2];
            }
            else {
                sum += (mat[i][col2]-mat[i][col1-1]);
            }
        }
        
        
        
        
        
        
        
        // for(int i = 0; i < mat.size(); i++) {
        //     for(int j = 0; j < mat[i].size(); j++) {
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */