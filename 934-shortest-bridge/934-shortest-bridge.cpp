class Solution {
public:
    
    queue<pair<int,int>> q;
    int n;
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 or i >= n or j < 0 or j >= n or grid[i][j] == 0 or grid[i][j] == 2) return;
        
        grid[i][j] = 2;
        q.push({i,j});
        
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    
    
    int bfs(vector<vector<int>> &grid) {
        int d(0);
        vector<int> dir = {-1,0,1,0,-1};
        
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto cell = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = cell.first + dir[i];
                    int y = cell.second + dir[i+1];
                    if(x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == 1) {
                        return d;
                    }
                    else if(x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == 0) {
                        grid[x][y] = 2;
                        q.push({x,y});
                    }   
                }
            }
            d += 1;
        }
        return 0;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool flag = false;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid,i,j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        return bfs(grid);
    }
};