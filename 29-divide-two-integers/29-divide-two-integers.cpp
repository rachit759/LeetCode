class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor) return 1;
        
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        
        if(dividend==INT_MAX && divisor==1) return INT_MAX;
        if(dividend==INT_MAX && divisor==-1) return -INT_MAX;
        
        cout<<INT_MAX<<endl;
        cout<<INT_MIN;
        
        
        bool isPositive = (dividend<0 == divisor<0);
        
      
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        
        unsigned int ans = 0;
        
        while(a >= b){  
            int q = 1;
            while(a > (b<<(q))) q++;
            
            q-=1;
            ans += (1<<q);  
            a = a - (b<<q);  
        }
        
       
        return isPositive ? ans : -ans;
    }
};