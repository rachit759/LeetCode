class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        //vector<int> ans(2);
        int n(size(nums)), count(0);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1])  { ++count; ++i;}; 
        }
        
        return {count,n- (count*2)};
        
    }
};