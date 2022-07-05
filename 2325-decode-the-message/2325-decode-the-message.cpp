class Solution {
public:
    string decodeMessage(string key, string message) {
        
        unordered_map<char,char>  mp;
        int count = 0;
        
        for(auto c : key) {
            if(c == ' ') continue;
            if(mp.find(c) == mp.end()) {
                mp[c] = 'a' + count;
                count++;
            }
        }
        
        mp[' '] = ' ';
        for(auto &i : message) {
            i = mp[i];
        }
        
        return message;
    }
};