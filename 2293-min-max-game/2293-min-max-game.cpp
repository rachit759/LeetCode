class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        helper(nums,0);
        return nums[0];
    }
    
    
    void helper(vector<int> &nums, int mins) {
        
        if(nums.size() == 1) return ;
        
        int j = 0;
        for(int i = 0; i <= nums.size()-2; i+=2) {
            if(mins == 0) nums[j++] = min(nums[i],nums[i+1]);
            else nums[j++] = max(nums[i],nums[i+1]);
            
            mins = !mins;
        }
        
        nums.resize(nums.size()/2);
        helper(nums,0);
        
        //return nums[0];
        
    }
    
    
};