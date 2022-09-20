// LC 2024
// LC 424
// this problem can be translated as subarrays with maximum count of zeroes as k

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i, j, zerocount, ans = INT_MIN;
        i = j = zerocount = 0;
        
        while(j < size(nums)) {
            if(nums[j] == 0) zerocount += 1;
            while(zerocount > k) {
                if(nums[i] == 0) zerocount -= 1;
                i += 1;
            }
            ans = max (ans,j-i+1);
            j += 1;
        }
        return ans;
    }
};