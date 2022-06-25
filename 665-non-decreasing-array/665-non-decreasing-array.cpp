class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        if(n == 1 or n == 2) return 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) {
                if(++count > 1) return false;
                if(i==1 or nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];      
            }
        }
        return true;
    }
};