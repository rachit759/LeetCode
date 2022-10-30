class Solution {
public:
    bool isvalid(int i, int j, int m, int n) {
        return i >= 0 and i < m and j >= 0 and j < n ;
    }
    
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        
        int m(size(grid)), n(size(grid[0]));
        vector<vector<int>> vis(m, vector<int>(n,-1));   // using visited array at a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        
        queue<array<int,4>> q;
        int dir[] = {-1,0,1,0,-1};
        
        int steps = 0;
        q.push({0,0,0,k});
        vis[0][0] = 0;
        
        int flag =0;
        while(q.size()) {
            array<int,4> cell = q.front();
            q.pop();
            int r = cell[0];
            int c = cell[1];
            int rem = cell[3];
            int steps = cell[2];
            if(rem < 0) continue;
            if(r + c == m + n - 2) {
                return steps;
            };
             
            for(int i = 0; i < 4; i++) {
                int x = r + dir[i];
                int y = c + dir[i+1];
                
                if(isvalid(x,y,m,n)) {
                    
                    if(grid[x][y] == 1) {
                        if(vis[x][y] == -1 or vis[x][y] < rem-1) {
                            q.push({x,y,steps+1,rem-1});
                            vis[x][y] = rem-1;
                        }
                    }
                    else {
                        
                        if(vis[x][y] == -1 or vis[x][y] < rem) {
                            q.push({x,y,steps+1,rem});
                            vis[x][y] = rem;
                        }
                    }
                    
                    
                    
                    
                }   
            }
            
            
            
        }
        
        return -1;
       
        
        
        
    }
};