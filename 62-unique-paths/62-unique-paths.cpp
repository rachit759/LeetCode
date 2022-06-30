class Solution {
public:
    int uniquePaths(int m, int n) {
 
        int nn=m+n-2;
        int rr=m-1;
        
        long double res  = 1;
        
        for(int i= 1;i<=rr;i++)
        {
           res = res * (nn)/i ;
            nn-=1;
        }
        
        return (int)res;

    }
};