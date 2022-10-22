class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>  mp;
        
        for(char i : t) mp[i]++;
        
        int i(0), j(0), start, len(INT_MAX), counter(size(t)), n(size(s));
        
        while(j < n) {
            --mp[s[j]];
            if(mp[s[j]] >= 0) --counter;
            while(i < n and counter == 0) {
                if(j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) ++counter;
                i++;
            }
            j++;
        }
        
        return len == INT_MAX ? "" : s.substr(start,len);
         
    }
};