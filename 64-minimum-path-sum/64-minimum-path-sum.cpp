class Solution {
public:

    int dfs(int i, int j,int m,int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==m-1 and j==n-1 ) return grid[i][j];
        if(i>=m or j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = grid[i][j] + min(dfs(i+1,j,m,n,grid,dp),dfs(i,j+1,m,n,grid,dp));
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m(size(grid)), n(size(grid[0]));
         
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return dfs(0,0,m,n,grid,dp);
        
        
    }
    
    
    
    
}; 