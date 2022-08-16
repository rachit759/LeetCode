class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        
        int n(size(grid));
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        
        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < n-1; j++) {
                int maxi = INT_MIN;
                for(int row = i-1; row <= i+1; row++) {
                    for(int col = j-1; col <= j+1; col++) {
                        maxi = max(maxi,grid[row][col]);
                    }
                }
                
                ans[i-1][j-1] = maxi;
            }
        }
        
        return ans;
        
    }
};