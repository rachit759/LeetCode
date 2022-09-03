class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,bool>  mp;
        int temp, n(size(nums));
        for(int i = 1; i < n; i++) {
            temp = nums[i-1] + nums[i];
            if(mp.count(temp)) return true;
            else mp[temp] = true;
        }
        return false;
    }
};