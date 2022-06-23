class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        
        if(n <= 0) return false;
        //  int count =0;
        // while(n!=0)
        // {
        //     int rs= n & -n;
        //     n-=rs;
        //     count++;
        // }
        // return (count==1)?true:false;
        
        return ceil(log2(n)) == floor(log2(n));
    }
};