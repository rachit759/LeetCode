class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        unordered_map<char,int> mp;
        
        for(auto i : s) {
            mp[i]++;
        }
        
        for(auto i : t) {
            mp[i]--;
            if(mp[i] < 0) return false;
        }
        return true;
    }
};