
//maximum sum of non adjacent elements in a subsequence

class Solution {
public:
    
//     int dfs(int i, vector<int>& nums, vector<int>& dp) {
//         if(i == 0) return nums[i];
//         if(i < 0) return 0;
//         if(dp[i] != -1) return dp[i];
//         int pick = nums[i] + dfs(i-2,nums,dp);
//         int notpick = dfs(i-1,nums,dp);
//         return dp[i] = max(pick,notpick);
//     }
    
    
    
    
    int rob(vector<int>& nums) {
        int n(size(nums));
        vector<int> dp(n,-1);
        
        int prev = nums[0];
        int prev2 = 0;
        int curr;
        for(int i = 1; i < n; i++) {
            
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notpick = 0 + prev;
            curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
        //return dfs(nums.size()-1,nums,dp);
    }
};