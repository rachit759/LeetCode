//class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();
//         int prefix[n], suffix[n];
        
//         prefix[0] = height[0];
        
//         for(int i = 1; i<n; i++)
//         prefix[i] = max(prefix[i-1],height[i]);
        
//         suffix[n-1] = height[n-1];           calculate prefix and suffix maximum and then ans 
                                                 //space complxity order of 2n
        
//         for(int i=n-2;i>=0;i--)
//         suffix[i] = max(suffix[i+1],height[i]);
        
//         int water=0;
        
//         for(int i=0;i<n;i++)
//             water+= min(prefix[i],suffix[i]) - height[i];
        
//         return water;
        
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();        
        int left = 0, right = n-1, leftmax = 0, rightmax = 0;   // order of n solution using two pointer approach 
                              // and calculating leftmax and rightmax 
        int water = 0;
        while(left < right) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftmax) leftmax = height[left];
                else water += leftmax-height[left];
                left++;
            }
            else {
                if(height[right] >= rightmax) rightmax = height[right];
                else water += rightmax-height[right];
                right--;
            }
        }
    
        return water;
        
    }
};
























