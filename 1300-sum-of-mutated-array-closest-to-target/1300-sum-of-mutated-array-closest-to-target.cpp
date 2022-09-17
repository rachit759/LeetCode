class Solution {
public:
    
    int check(vector<int> &nums, int mid) {
        int sum = 0;
        for(int a : nums) {
            if(a <= mid) sum += a;
            else sum += mid;
        }
        return sum;
    }
    
    
    int findBestValue(vector<int>& nums, int target) {
        int low = 0;
        int high = *max_element(begin(nums), end(nums));
        
        int ans = high;
        int mindiff = target;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            int sums = check(nums,mid);
            int diff = abs(target-sums);
            
            if(diff < mindiff) {
                mindiff = diff;
                ans = mid;
            }
            
            if(diff == mindiff) ans = min(ans,mid);
            
            if(sums > target) high = mid-1;
            else low = mid + 1;
            
        }
        
        return ans;
        
    }
};