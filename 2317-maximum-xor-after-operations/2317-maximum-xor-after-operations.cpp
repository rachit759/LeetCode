// nums[i] & (nums[i]^x) cannot be more than nums[i] because we are taking AND.
// So this implies that for any number we can set the bits OFF ***(only the bits which are already ON (1))***.
// BUT we cannot set any bitONif it were OFFalready .

// Therefore , we can say that we will set bits ON and OFF for all numbers in such a way that XOR of all the numbers is equal to OR of all numbers. Because if a bit is not on in any of the numbers ,there is no way we can get it on in our ans.



class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int ans = 0;
        
//         vector<int> bits(32,0);
        
//         for(auto n : nums) {
//             for(int i = 0; i < 32; i++) {
//                 if(n & (1<<i)) bits[i] = 1;
//             }
//         }
        
//         //for(auto i : bits) cout<<i<<" ";
        
//         int ans = 0;
        
//         for(int i = 0; i < 32; i++) {
//             if(bits[i]) ans += (1<<i); 
//         }
        for(auto i : nums) {
		    ans |= i;
        }
        
        return ans;
    }
};