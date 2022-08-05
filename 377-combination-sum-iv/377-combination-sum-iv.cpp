class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> &nums, int target) {
        
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        int ways = 0;
        
        for(auto ele : nums) {
            if(ele <= target) ways += dfs(nums,target - ele);
        }
        dp[target] = ways;
        return ways;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
       dp = vector<int>(target+1,-1);
       return dfs(nums,target); 
    }
};