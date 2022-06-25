class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int k) {
        
        int n(size(nums));
        int count(1);
        vector<int> dec(n,0), inc(n), ans;
        
        if(k == 0) {
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }
        dec[0] = inc[n-1] = 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i-1] >= nums[i]) {
                ++count;
            }
            else count = 1;
            dec[i] = count;
    
        }
        
        count = 1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] <= nums[i+1]) {
                ++count;
            }
            else count = 1;
            inc[i] = count;
    
        }
        
        //for(auto i : inc) cout<<i<<" ";
        
        for(int i = k; i <= n-k-1; i++) {
            if(dec[i]-1>=k and inc[i] -1>= k) ans.push_back(i);
        }
        
        return ans;
    }
};