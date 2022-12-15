class Solution {
public:
    
    int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        if(i == a.size() or j == b.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + lcs(i+1,j+1,a,b,dp);
        else return dp[i][j] = max(lcs(i+1,j,a,b,dp),lcs(i,j+1,a,b,dp));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1000, vector<int>(1000,-1));
        lcs(0,0,text1,text2,dp);
        return dp[0][0];
    }
};



// dp
