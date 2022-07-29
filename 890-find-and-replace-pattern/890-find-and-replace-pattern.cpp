class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
        
        
        
        vector<string> ans;
        int n(size(pat));
        
        for(auto word : words) {
            unordered_map<char,char>  mp;
            unordered_set<char>  s;
            int flag = 1;
            for(int i = 0; i < n; i++) {
                if(mp.find(pat[i]) == mp.end()) {
                    if(s.count(word[i]) == 1) {
                        flag = 0;
                        break;
                    }
                    else {
                    mp[pat[i]] = word[i];
                    s.insert(word[i]); 
                    }
                }
                else {
                    if(mp[pat[i]] != word[i]) {
                        flag = 0;
                        break;
                    } 
                }
            }
            if(flag == 1) ans.push_back(word);
           
        }
        
        return ans;
        
        
    }
};