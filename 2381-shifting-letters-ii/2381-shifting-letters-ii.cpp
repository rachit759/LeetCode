
// linesweep
// scanline algorithm to work on q queries 
// basically a[l]++ and a[r+1]-- and then build the prefix array of that 
// all the queries will be resolved

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& q) {
        
        int n = s.size();
        vector<int> shift(n,0);

        
        for(int i = 0; i < q.size(); i++) {
            shift[q[i][0]] += (q[i][2] == 0 ? -1 : 1);
            if(q[i][1] + 1 < n) shift[q[i][1] + 1] -= (q[i][2] == 0 ? -1 : 1);          // working on l and r range
        } 
        
        for(int i = 1; i < n; i++) {           // building the prefix array
            shift[i] += shift[i-1];
        }
    
    
        for(int i = 0; i < n; i++) {                     // working on string to convert it
            int move = (s[i] -'a' + shift[i]) % 26;
            if(move < 0) move += 26;           
            s[i] = move + 'a';
        }
        
        return s;
        
    }
};