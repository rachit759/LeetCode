class Solution {
public:
    int minDeletions(string ss) {
        
        vector<int> mp(26,0);
        
        for(char i : ss) mp[i-'a']++;
        
        unordered_set<int> seen;
        
        int ans = 0;
        
        for(auto i : mp) {
            
            while(i !=0 and seen.find(i) != seen.end()) {
               i--;
               ++ans; 
            }
            
            seen.insert(i);
        }
        
        
        return ans;
        
    }
};