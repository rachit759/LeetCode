class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        
        vector<vector<int>> grid(m, vector<int>(n,0) );
        
        
        for(auto vec : guards) {
            grid[vec[0]][vec[1]] = 1;
        }
        
        for(auto vec : walls) {
            grid[vec[0]][vec[1]] = 2;
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    
                    int left = j+1;
                    while(left < n and grid[i][left] != 1 and grid[i][left] != 2)
                        grid[i][left++] = 3;
                    
                    int right = j-1;
                    while(right >= 0 and grid[i][right] != 1 and grid[i][right] != 2)
                        grid[i][right--] = 3;
                    
                    int up = i-1;
                    while(up >= 0 and grid[up][j] != 1 and grid[up][j] != 2)
                        grid[up--][j] = 3;
                    
                    int down = i+1;
                    while(down < m and grid[down][j] != 1 and grid[down][j] != 2)
                        grid[down++][j] = 3;
                    
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    
                    count += 1;
                    
                }
            }
        }
        
        
        return count;
        
    }
};