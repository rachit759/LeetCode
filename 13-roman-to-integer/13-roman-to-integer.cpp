class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        
        int ans = 0;
        
        int n = s.length();
        
        for(int i = 0; i < n-1; i++) {
            if(mp[s[i]] < mp[s[i+1]] ) ans -= mp[s[i]];
            else
                ans += mp[s[i]];
            
        }
        
        return ans+=mp[s[n-1]];
    }
};