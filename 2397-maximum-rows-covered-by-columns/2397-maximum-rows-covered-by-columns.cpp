class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int m(size(mat)), n(size(mat[0]));
        int ans = 0, rows;
        bool flag;
        for(int mask = 1; mask <= (1<<n); mask++) {
            if(__builtin_popcount(mask) != cols) continue; 
            
            vector<int> col_set(n,0);
            rows = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1<<i)) {
                    col_set[i] = 1;
                }
            }
            
            for(int i = 0; i < m; i++) {
                flag = true;
                for(int j = 0; j < n; j++) {
	                if(col_set[j] != 1 and mat[i][j] == 1) {
                        flag = false;
                        break;
                    }
                    
                }
                if(flag) rows += 1;
            }
            ans = max(ans,rows);
        }
        
        return ans;
        
    }
};