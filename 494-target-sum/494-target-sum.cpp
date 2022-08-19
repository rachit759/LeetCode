class Solution {
public:
    int dp[21][2002];
    int helper(int i, vector<int> &nums, int sum, int target) {
        if(i == nums.size()) {
          return sum == target;
        }
        if(dp[i][sum+1000] != -1) return dp[i][sum+1000];
        return dp[i][sum+1000] = helper(i+1,nums,sum+nums[i],target) + helper(i+1,nums,sum-nums[i],target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(0,nums,0,target);
    }
};