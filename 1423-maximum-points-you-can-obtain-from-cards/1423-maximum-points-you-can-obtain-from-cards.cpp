class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        
        int i(0), j(0) ,n(size(nums)), score(INT_MAX),sum(0);
        int sums = accumulate(begin(nums), end(nums), 0);
       // cout<<sums;
        int sz = n-k;
        if(sz == 0) return sums;
        while(j < n) {
            sum += nums[j];
            if(j-i+1 == sz) {
                score = min(score,sum);
                sum -= nums[i++];
            }
            j++;
        }
        //cout<<score;
        return sums-score;
        
    }
};