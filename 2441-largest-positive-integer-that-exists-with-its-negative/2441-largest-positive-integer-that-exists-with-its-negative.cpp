class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int mx = INT_MIN;
        int n(size(nums));
        unordered_set<int> s;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) s.insert(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0 and s.count(abs(nums[i]))) 
                mx = max(mx,abs(nums[i]));
        }
        //cout<<mx;
        return mx == INT_MIN ? -1 : mx;
        
    }
};