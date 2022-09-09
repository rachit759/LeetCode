class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n(size(nums)), i(0), j(0), bitsunion(0), res(0);
        
        while(j < n) {
            while((bitsunion & nums[j]) != 0) {
                bitsunion ^= nums[i++];
            }
            res = max(res,j-i+1);
            bitsunion |= nums[j++];
        }
        return res; 
    }
};