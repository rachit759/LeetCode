class Solution {
public:
    string bfs(string s) {
        int i = 0, count = 1, n = s.size();
        string t;
        while(i < n) {
            if(i + 1 < n and s[i] == s[i+1]) {
                count += 1;
            }
            else {
                t += to_string(count) + s[i];
                count = 1;
            }
            i += 1;
        }
        return t;
    }
    
    string countAndSay(int n) {
        if(n == 1) return "1";
        string t = to_string(1);
        for(int i = 1; i <= n-1; i++) {
            t = bfs(t);
        }
        
        return t;
    } 
};