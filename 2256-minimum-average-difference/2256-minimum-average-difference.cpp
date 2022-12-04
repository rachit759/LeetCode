class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();

        vector<long long> prefix(n,0);
        
        
        prefix[0] = nums[0];
        
     
        
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        long long sums = prefix[n-1];
        
        int mini = INT_MAX, sum=0, index;
        
        for(int i = 0; i < n; i++) {
            
            
            if(n-i-1 > 0) sum = abs( (prefix[i]/(i+1)) - ((sums-prefix[i])/(n-i-1)) );
            else sum = prefix[i] / n;
            
            if(sum < mini) {
                mini = sum;
                index = i;
            }
            
        }
        
        return index;
        
        
    }
};


// better approach



// class Solution {
// public:
//     int minimumAverageDifference(vector<int>& nums) {
        
//         int n(size(nums)), minAverageDifference(INT_MAX), index;
        
//         long long sumFromFront(0), sumFromEnd(0);
//         for (auto& num : nums) sumFromEnd += num;
        
//         for (int i=0; i<n; i++) {
//             sumFromFront += nums[i];
//             sumFromEnd -= nums[i];
//             int a = sumFromFront / (i+1); // average of the first i + 1 elements.
//             int b = (i == n-1) ? 0 : sumFromEnd / (n-i-1); // average of the last n - i - 1 elements.
            
//             if (abs(a-b) < minAverageDifference) {
//                 minAverageDifference = abs(a-b);
//                 index = i;
//             }
//         }
//         return index;
//     }
// };