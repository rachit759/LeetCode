class Solution {
public:
    long dp[50][50][51];
    int mod = 1000000007;
    long dfs(int m, int n, int i, int j, int moves) {
        if(i < 0 or i == m or j < 0 or j == n) return 1;
        if(moves == 0) return 0;
        
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        
        return dp[i][j][moves] = (dfs(m, n, i-1, j, moves - 1)%mod + dfs(m, n, i, j-1, moves - 1)%mod + dfs(m, n, i+1, j, moves - 1)%mod + dfs(m, n, i, j+1, moves - 1) %mod) % mod;
      
    }
    
    
    
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,startRow,startColumn,maxMove) % mod;
        
        
        
    }
};