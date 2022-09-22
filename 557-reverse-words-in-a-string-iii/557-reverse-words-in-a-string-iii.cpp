class Solution {
public:
    string reverseWords(string s) {
        
        string p;
        
        stringstream ss(s);
        
        string word;
        
        while(ss >> word) {
            
            reverse(word.begin(),word.end());
            
            p += word + " ";
            
        }
        
        p.pop_back();
        
        return p;
    }
};