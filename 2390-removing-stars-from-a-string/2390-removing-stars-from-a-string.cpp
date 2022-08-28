class Solution {
public:
    string removeStars(string s) {
    
        string temp;
        for(auto c : s) {
            if(c == '*') temp.pop_back();
            else temp.push_back(c);
        }
        
        return temp;
    }
};