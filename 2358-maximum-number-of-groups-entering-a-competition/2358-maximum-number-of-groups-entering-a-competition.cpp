class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        
        
        int n(size(nums));
        
        
        int count = 1;
        
        while(n-count>= 0) {
            n -= count;
            count += 1;
        }
        
        return count-1;
        
    }
};