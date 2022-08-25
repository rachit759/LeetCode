class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> m(26,0);
        vector<int> r(26,0);
        
        
        for(auto i : magazine)
            m[i-'a']++;
            
        
        for(auto i : ransomNote)
            r[i-'a']++;
            
          
        for(int i = 0; i < 26; i++) {
            m[i] -= r[i]; 
            if(m[i] < 0) return false;
        }
        
        return true;
        
    }
};