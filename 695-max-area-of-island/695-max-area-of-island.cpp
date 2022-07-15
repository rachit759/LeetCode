class Solution {
public:
     int helper(vector<vector<int>>& grid, int i,int j,int r,int c) {
       
        if(i<0 or i>=r or j<0 or j>=c or grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        
        return 1 + helper(grid,i-1,j,r,c) + helper(grid,i+1,j,r,c) + helper(grid,i,j+1,r,c) + 
             helper(grid,i,j-1,r,c);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int area = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0 ;j < n; j++) {
                if(grid[i][j]) {
                    area = max(area,helper(grid,i,j,m,n)); 
                }
            }
        }
        
        return area;
        
    }
     
};