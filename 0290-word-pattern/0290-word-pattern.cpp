class Solution {
public:
    bool wordPattern(string pat, string s) {
        
        unordered_map<char,string> mp;
             
        int n = pat.length();
        stringstream sss(s);
        string word;
        int count =0;
        while(sss>>word) ++count;
        
        if(n != count) return false;
        
        stringstream ss(s);
        word="";
   
        set<string> t;
        
        for(int i = 0; i < n; i++) {
  
            ss >> word;
            t.insert(word);
            if(mp.find(pat[i]) == mp.end()) {
                mp[pat[i]] = word;
            }
            else {
                if(mp[pat[i]] != word) return false;
            }
            
        }
        
        if(mp.size() != t.size()) return false; 
        
        return true;
        
    }
};