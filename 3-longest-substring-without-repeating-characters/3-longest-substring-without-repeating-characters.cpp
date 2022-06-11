class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left(0), right(0), len(0);
        vector<int> mp(256,0);
        
        while(right < s.size()) {
            
            mp[s[right]]++;
            
            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            len = max(len,right-left+1);
            right++;
        }
        
        return len;           
    }
};