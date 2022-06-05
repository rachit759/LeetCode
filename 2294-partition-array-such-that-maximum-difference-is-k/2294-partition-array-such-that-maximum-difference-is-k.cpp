class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(begin(nums),end(nums));
        int count = 1;
        int mx, mn;
        mx = mn = nums[0];
        for(auto a : nums) {
            mn = min(mn,a);
            mx = max(mx,a);
            if(mx - mn > k) {
                count += 1;
                mn = mx = a;
            }
        }
    
        
        return count;
    }
};