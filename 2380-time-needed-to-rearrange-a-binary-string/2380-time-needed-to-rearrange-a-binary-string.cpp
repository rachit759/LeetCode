class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int time = 0;
        int n = s.size();
        bool flag ;
        
        while(true) {
            flag = false;
            
            for(int i = 1; i < n; i++) {
                if(s[i-1] == '0' and s[i] == '1') {
                    swap(s[i-1],s[i]);
                    i += 1;
                    flag = true;
                }
            }
            
            if(!flag) break;
            time += 1;
        }
        
        
        return time;
        
    }
};