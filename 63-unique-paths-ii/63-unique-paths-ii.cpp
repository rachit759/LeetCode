class Solution {
     int countpaths(vector<vector<int>>& og,int i,int j, int m, int n, vector<vector<int>> &dp)
    {
          if(i<0 or j<0 or i>=m or j>=n or og[i][j]==1)
            return 0;
         
         if(dp[i][j]!=-1) return dp[i][j];
         
        if(i==m-1 and j==n-1 ) return 1;
     
        
        return dp[i][j]= countpaths(og,i+1,j,m,n,dp) + countpaths(og,i,j+1,m,n,dp);
    }
    
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        
            int n  = og[0].size();
        
           vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return countpaths(og,0,0,m,n,dp);
    }
};





