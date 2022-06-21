class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int zero = count(begin(s),end(s),'0');
        int len(0),num(0),base(1),n(size(s));
        
        for(int i = n-1; i >= 0 and num + base <= k; i--) {
            
            if(s[i] == '1') num += base;
            else zero -= 1;
            
            base *= 2;
            len += 1;
        }
        
        return zero + len;
        
    }
};