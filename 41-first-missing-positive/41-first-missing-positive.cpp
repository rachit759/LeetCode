class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {                 // making all the number out of range equal to n+1
            if(nums[i]<=0 or nums[i] > n) 
                nums[i] = n + 1;
        }
        
        for(int i = 0; i < n; i++) {
             
            int index =  abs(nums[i]) - 1;                          // consider index as the number
            if(index >=0 and index<n and nums[index]>0)             // 0 index means 1 , 1 index means 2 and so onn
                nums[index] *= -1;
        }
        
        for(int i = 0; i < n; i++) { 
            if(nums[i]>0) return i+1;                           // the number is positive that is missing
        }
        
        return n+1;
        
    }
};