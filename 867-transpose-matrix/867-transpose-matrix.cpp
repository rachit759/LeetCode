class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> ans;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < m; j++) {
                    temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};