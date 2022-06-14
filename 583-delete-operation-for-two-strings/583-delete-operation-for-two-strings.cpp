// longest common subsequence

class Solution {
public:
    int lcs(string a, string b) {
        
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
       return dp[m][n]; 
        
    }
    
    
    int minDistance(string word1, string word2) {
        return size(word1) + size(word2) - 2 * lcs(word1, word2);
    }
};