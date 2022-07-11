// bucket sort

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        vector<int> diff(100001,0);     // i = number / diff[i] = freq
        int k = k1 + k2, freq;
        for(int i = 0; i < nums1.size(); i++) {
            diff[abs(nums1[i]-nums2[i])]++;
        }
        
        for(int i = 100000; i >= 1; i--) {
            freq = diff[i]; 
            if(freq <= k) {
                if(i == 1) return 0;
                diff[i] = 0;
                diff[i-1] += freq;
                k -= freq;
            }
            else {
                diff[i] -= k;
                diff[i-1] += k;
                break;
            }  
        }
        
        long long ans = 0;
        
        for(int i = 100000; i >= 1; i--) {
            ans += 1LL * diff[i] * i * i;
        }
        
        return ans;
        
    }
};