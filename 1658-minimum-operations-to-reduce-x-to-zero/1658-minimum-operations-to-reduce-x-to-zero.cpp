class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        int k = accumulate(nums.begin(),nums.end(),0);
        if(k==x) return n;
        k = k- x;
        int  i=0;
        int j=0;
        int len=0;
        int sum =0;
        
        while(j<n)
        {
            sum+=nums[j];
            while(i<j and sum >k)
            {
                sum-=nums[i++];
                
            }
            if(sum ==k)
                len = max(len , j-i+1);
            
            j++;
            
        }

     if(len==0)
         return -1;
            return n-len;
    }
};


/*

class Solution {
public:
    int minOperations(vector<int>& n, int x) {
          int size = n.size();
          int total = 0;
          int len = 0;
          for(int i : n) total += i;
          if(total == x) return size;
          int need = total - x;
          int i = 0 , j = 0;
          int sum = 0;
          while( j < size ) {
                sum += n[j];  
                while(i < j && sum > need){
                        sum -= n[i++];
                }
                if(sum == need){
                    
                    len = max(len, j-i+1);
                }
                j++;
          } 
          if(len == 0) return -1;  
          return size-len;
    }
};


*/













