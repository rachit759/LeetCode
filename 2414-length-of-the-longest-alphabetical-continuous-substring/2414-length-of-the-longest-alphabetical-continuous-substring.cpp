class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int maxl = 1;
        int ans = 1;
        for(int i = 1; i < size(s); i++) {
            if(char(s[i-1] + 1) == s[i]) maxl++;
            else {
                ans = max(ans,maxl);
                maxl = 1;
            }
        }
        return max(ans,maxl);
    }
};