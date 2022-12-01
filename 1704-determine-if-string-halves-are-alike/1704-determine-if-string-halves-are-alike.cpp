class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.size();
        //unordered_map<char,int>  mp;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i < n/2 and (tolower(s[i]) == 'a' or tolower(s[i]) == 'e' or tolower(s[i]) == 'i' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u')) count += 1;
            else if(tolower(s[i]) == 'a' or tolower(s[i]) == 'e' or tolower(s[i]) == 'i' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u') count -= 1;
        }
        
                
        return count == 0;
    }
};