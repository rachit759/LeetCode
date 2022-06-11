class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mp) {
        
        
        int m(size(s)), n(size(sub));
        unordered_map<char,unordered_set<char>> maping;
        
        for(auto vec : mp) {
            maping[vec[0]].insert(vec[1]);
        }
        
        for(int i = 0; i <= m-n; i++) {
            
            bool flag = 0;
            for(int j = 0; j < n; j++) {
                if(sub[j] != s[i+j] and maping[sub[j]].find(s[i+j]) == maping[sub[j]].end()) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return true;
        }
        
        
        return false;
        
    }
};