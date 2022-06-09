class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        
        int i = 0, n = nums.size(), j = n-1;
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) return {++i,++j};
            else if(sum > target) j--;
            else i++;
        }
        
        return {};
        
    }
};