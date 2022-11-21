class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};    
    bool isvalid(int i, int j, int m, int n) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        
        int m = maze.size(), n = maze[0].size();
        
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        // cout<<maze[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        queue<pair<int,int>> q;
        maze[e[0]][e[1]] = '+';
        for(int i = 0; i < 4; i++) {
            int x = e[0] + dir[i];
            int y = e[1] + dir[i+1];
            if(isvalid(x, y, m, n) and maze[x][y] == '.') {
                q.push({x, y});
                maze[x][y] = '+';
            }
                
        }
        
        int steps = 1;
        if(!q.size()) return -1;
        
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto [x,y] = q.front();
                q.pop();
                if(x == 0 or x == m-1 or y == 0 or y == n-1) return steps;
                for(int i = 0; i < 4; i++) {
                    if(isvalid(x + dir[i], y + dir[i+1], m, n) and maze[x+dir[i]][y+dir[i+1]] == '.') {
                        q.push({x + dir[i], y + dir[i+1]});
                        maze[x+dir[i]][y+dir[i+1]] = '+';
                    }
                }   
            }
            steps += 1;
        }
        return -1;
    }
};