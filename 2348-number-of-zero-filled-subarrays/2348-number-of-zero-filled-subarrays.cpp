class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long sum(0);
        
        int i(0), j(0), n(size(nums));
        
        while(j < n) {
            
            if(nums[j] != 0) i++, j++;
            
            else if(nums[j] == 0) {
                i = j;
                while(j < n and nums[j] == 0) {
                    int len = j-i+1;
                    sum += len;
                    j++;
                }
            }
            
        }
        
        return sum;
        
    }
};