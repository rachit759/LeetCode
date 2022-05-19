class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            if(words[i] == s.substr(0,words[i].length())) count+=1;
        }
        
        return count;
    }
};