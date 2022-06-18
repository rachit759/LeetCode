class WordFilter {
public:
    unordered_map<string,int>  mp;
    
    WordFilter(vector<string>& words) {
    
        int n(size(words));
        
        for(int i = 0; i < n; i++) {
            
            string word = words[i];
            int sz(size(word));
            for(int j = 1; j <= sz; j++) {
                string p = word.substr(0,j);
                
                for(int k = 0; k < size(word); k++) {
                    
                    string s = word.substr(k,sz);
                    mp[p + "*" + s] = i + 1;
                }
            }
            
        }
        
        
        
        
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + "*" + suffix] - 1; 
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */