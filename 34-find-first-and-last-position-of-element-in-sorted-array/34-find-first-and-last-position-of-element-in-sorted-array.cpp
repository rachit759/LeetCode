class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        
        int n = nums.size();
        
        if(n == 0) return res;
        
        int start = 0, end = n-1;
        int ans = INT_MIN ;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] >= target) end = mid-1,ans=nums[mid];
            else start = mid + 1;
            
        }
        
        if(ans != target) return res;
        
        res[0] = start;
        
        end = n-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] <= target) start = mid + 1;
            else end = mid - 1;
            
        }
        res[1] = end;
        
        return res;
    }
};