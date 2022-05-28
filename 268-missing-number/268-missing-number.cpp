class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        long long sums = 0;
       for (int ele : nums)
            sums += (long long)ele;
        
        
        
        // int xr =0;
        // int tx =0;
        
        // for ( int n : nums)
        //    xr^=n;
        
        int n =nums.size();
        
//         for( int i=0 ;i<=n;i++)
//             tx^=i;
        
//         return xr^tx;
        
        long sum = (n * (n+1) ) /2;
        
        return sum == sums ? 0 : sum-sums;
        
        
        
    }
};