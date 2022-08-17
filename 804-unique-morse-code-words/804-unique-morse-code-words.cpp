class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> mp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        string temp;
        for(int i = 0; i < size(words); i++) {
            temp.clear();
            
            for(auto it : words[i]) {
                temp += mp[it-'a'];
            }
            s.insert(temp);
        }
        
        return s.size();
    }
};