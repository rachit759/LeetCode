class Solution {
public:
    string reverseVowels(string s) {
        string temp;
        for(char &c: s) {
            if(tolower(c) == 'a' or tolower(c) == 'e' or tolower(c) == 'i' or tolower(c) == 'o' or tolower(c) == 'u') {
                temp += c;
            }
        }
        //cout<<temp;
        reverse(begin(temp),end(temp));
        int i = 0;
        for(auto &c: s) {
            if(tolower(c) == 'a' or tolower(c) == 'e' or tolower(c) == 'i' or tolower(c) == 'o' or tolower(c) == 'u') {
                c = temp[i++];
            }
        }
        
        return s;
        
    }
};