class Solution {
public:
    bool static compare(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    
    int LIS(vector<int>& nums) {
        
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
    
    int maxEnvelopes(vector<vector<int>>& nums) {
    
        sort(begin(nums),end(nums),compare);
        
        vector<int> v;
        
        for(auto vec : nums) v.push_back(vec[1]);
        
        return LIS(v);
       
    }
};


