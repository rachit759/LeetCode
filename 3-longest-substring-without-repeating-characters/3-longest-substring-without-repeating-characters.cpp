class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left=0;
        int right=0;
        int n = s.length();
        int maxi=0;
        vector<int> mp(256,-1);
        
        while(right<n)
        {
            if(mp[s[right]]!=-1)
                left = max(mp[s[right]]+1,left);
                
                
           mp[ s[right]] = right;
            
            maxi = max(maxi,right-left+1);
            right++;
        }
            return maxi;
            
            
            
            
            
    }
};