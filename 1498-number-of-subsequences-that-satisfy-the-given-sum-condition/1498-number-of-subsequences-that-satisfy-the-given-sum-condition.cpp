class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count =0;
        vector<int> p(n+1);
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            p[i] = (p[i-1] * 2) % 1000000007;
        }
        
        int i=0, j= n-1;
        
        
        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                count = (count + p[j-i]) % 1000000007;
                i++;
            }
            else j--;
        }
        
        
     
        return count;
        
    }
};