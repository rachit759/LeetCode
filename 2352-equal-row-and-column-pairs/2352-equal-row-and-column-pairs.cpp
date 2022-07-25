class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n(size(grid));
        
        vector<vector<int>> ans = grid;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
	            if(i == j) continue;
                swap(grid[i][j],grid[j][i]);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
	            if(ans[i] == grid[j]) count += 1;
            }
        }
        
        return count;
    }
};