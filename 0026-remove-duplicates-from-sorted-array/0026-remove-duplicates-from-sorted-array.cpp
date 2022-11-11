class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        int i = 0;
        int j = 1;
        int n = nums.size(); 
        if(n==0 or n==1) return n;
        while(j<n)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
                j++;
        }
        
        return i+1;
    }
};