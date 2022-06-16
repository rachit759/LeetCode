#define pi pair<int,int>

class Solution {
public:
    bool isvalid(int i, int j, vector<vector<int>> &grid, int n) {
        return i>=0 and i<n and j>=0 and j<n and grid[i][j] != -1;
    }
    
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n(size(grid));
        
        int dir[] = {1,0,-1,0,1};
        
        priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> pq;
       
        
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        int ans = INT_MIN;
        
        while(!pq.empty()) {
            
            auto cell = pq.top();
            pq.pop();
            ans = max(ans,cell.first);
            if(cell.second.first + cell.second.second == 2*n-2) return ans;
            
            for(int i = 0; i < 4; i++) {
                int x = cell.second.first + dir[i];
                int y = cell.second.second + dir[i+1];
                
                if(isvalid(x,y,grid,n)) {
                    pq.push({grid[x][y],{x,y}});
                    grid[x][y] = -1;
                }
            }
        }
        
        
        return 0;
        
    }
};