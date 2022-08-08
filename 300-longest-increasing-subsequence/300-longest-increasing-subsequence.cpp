
//https://youtu.be/22s1xxRvy28
// stable sort or patience sort

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> vec;
        vec.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {

            if(vec.back() < nums[i]) vec.push_back(nums[i]);
            else if(vec.back() == nums[i]) continue;
            else {
                int low = 0, high = vec.size()-1;
                
                while(low <= high) {
                    int mid = low + (high-low)/ 2;
                    if(vec[mid] >= nums[i]) high = mid-1;
                    else low = mid + 1;
                }
                
                vec[low] = nums[i];
                
            }
        }
    
        
        
        return vec.size();
    }
};