class Solution {
public:
    bool dfs(vector<int> &m, int i, int side, int a, int b, int c, int d) {
        
        if(a > side or b > side or c > side or d > side) return 0;
        
        if(i == m.size()) {
            if(a == side and b == side and c == side and d == side) return 1;
            return 0;
        }
        
        return dfs(m,i+1,side,a+m[i],b,c,d)
        or dfs(m,i+1,side,a,b+m[i],c,d)
       or dfs(m,i+1,side,a,b,c+m[i],d)
       or dfs(m,i+1,side,a,b,c,d+m[i]);
      
    }
    
    
    
    
    bool makesquare(vector<int>& m) {
        
        if(m.size() < 4) return 0;
        int sum = accumulate(begin(m), end(m), 0);
        if(sum % 4 != 0) return 0;
        sum /= 4;
        sort(rbegin(m),rend(m));
        return dfs(m,0,sum,0,0,0,0);
        
        
    }
};