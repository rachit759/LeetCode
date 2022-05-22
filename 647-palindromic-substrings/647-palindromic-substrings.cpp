class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            count += helper(i,i,s,n);
            count += helper(i,i+1,s,n);
        }
        return count;
    }
    private:
        int helper(int start, int end, string s,int n) {
            int count = 0;
            while(start >= 0 and end < n and s[start--] == s[end++]) 
                count += 1; 
                

            return count;
        }
        
        
    
};