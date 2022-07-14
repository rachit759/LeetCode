class Solution {
public:
    bool canChange(string start, string target) {
        
        int i(0), j(0), n(size(start));
        
        while(i < n and j < n) {
            while(i < n and start[i] =='_') i++;
            while(j < n and target[j] =='_') j++;
            
            if(i==n or j==n) break;
            
            
            if(start[i] != target[j]) return false;
            
            if(start[i] == 'L' and i < j) return false;
            if(start[i] == 'R' and i > j) return false;
            
            i++, j++;
            
        }
        
        
        while(i < n and start[i] =='_') i++;
        while(j < n and target[j] =='_') j++;
        
        
        return i==n and j==n;
        
        
    }
};