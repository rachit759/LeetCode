class Solution {
public:
    string greatestLetter(string s) {
        vector<pair<int,int>> mp(26,{0,0});
        int n(size(s));
        string ans;
        for(int i = 0; i < n; i++) {
            
            if(isupper(s[i])) {
                
                mp[tolower(s[i]) - 'a'].second  = 1;
            }
            else mp[s[i]-'a'].first = 1;
            
            
        }
  
        for(int i = 25; i >= 0; i--) {
            
            if(mp[i].first and mp[i].second) { 
             
                string p;
                p+= char(toupper(char(i +'a')));
                return p;
            }
                
        }
        
        return ans;
    }
};