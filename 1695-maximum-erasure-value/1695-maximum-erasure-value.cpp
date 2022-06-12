class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int i(0), j(0), n(size(nums)), res(0), sum(0);
        unordered_map<int,int>  mp;
        
        while(j < n) {
            
           mp[nums[j]]++;
            while(mp[nums[j]] > 1) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            
            
            res = max(res,sum);
            j++;
            
        }
        
        return res;
        
    }
};