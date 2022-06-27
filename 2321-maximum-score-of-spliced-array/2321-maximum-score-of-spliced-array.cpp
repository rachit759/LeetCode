class Solution {
public:
    
    int kadane(vector<int> a, vector<int> b) {
        int sum = 0, res = 0, currsum = 0;
        for(int i = 0; i < a.size(); i++) {
            currsum = max(b[i]-a[i] , currsum + b[i]-a[i]);
            res = max(res,currsum);
            sum += a[i];
        }
        return sum + res; 
    }
    
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(kadane(nums1,nums2), kadane(nums2,nums1));
    }
};