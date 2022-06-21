// this is a trie question 
// doing this by brute force


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        
        unordered_set<string> s(begin(words),end(words));
        
        for(auto word : s) {
            for(int i = 1; i < word.size(); i++) {
                s.erase(word.substr(i));
            }
        }
        
        int res = 0;
        
        for(auto w : s) res += size(w) + 1;
        return res;
    }
};