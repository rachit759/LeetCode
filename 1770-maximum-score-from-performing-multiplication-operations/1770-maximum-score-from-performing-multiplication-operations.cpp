
// greedy wont work here
// due to even and odd 

class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& multi, int index, int left, int right,vector<vector<int>> &dp) {
        
        if(index == multi.size()) {
            return 0;
        }
        if(dp[left][index] != INT_MIN)
            return dp[left][index];
        
        int l = nums[left]*multi[index] + dfs(nums,multi,index+1,left+1,right,dp);
        int r = nums[right]*multi[index] + dfs(nums,multi,index+1,left,right-1,dp);
        return dp[left][index] = max(l,r);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& m) {
        vector<vector<int>> dp(m.size()+1 , vector<int>(m.size()+1,INT_MIN));   // dp of size of nums + size of multi
        return dfs(nums,m,0,0,nums.size()-1,dp);
    }
};