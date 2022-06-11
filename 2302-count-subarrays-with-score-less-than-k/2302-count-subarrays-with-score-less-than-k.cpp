class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long count = 0,sum =0;
        int n = nums.size();
       int i(0), j(0);
        
        while(j < n) {
            sum += nums[j];
            
            while(sum*(j-i+1) >= k) {
                sum -= nums[i++];
            }
            
            count += (j-i+1);
            
            j++;
        }
        
        
        return count;
        
        
        
    }
};