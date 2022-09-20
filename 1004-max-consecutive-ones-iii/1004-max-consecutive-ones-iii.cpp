// LC 2024
// LC 424
// this problem can be translated as subarrays with maximum count of zeroes as k

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i, j, zerocount, ans = INT_MIN, n = nums.size();
        i = j = zerocount = 0;
        
        while(j < n) {
            if(nums[j] == 0) ++zerocount;
            while(zerocount > k) {
                if(nums[i] == 0) --zerocount;
                i += 1;
            }
            ans = max (ans,j-i+1);
            ++j;
        }
        return ans;
    }
};