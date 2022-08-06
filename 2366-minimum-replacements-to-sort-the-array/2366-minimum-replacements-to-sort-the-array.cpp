class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
    
        int n(size(nums)), breaks, right = nums[n-1];
        long long count(0);
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= right) right = nums[i];
            else {
                breaks = (nums[i] + right - 1) / right;
                right = nums[i] / breaks;
                count += breaks - 1;
            }
        }
        
        return count;
        
    }
};