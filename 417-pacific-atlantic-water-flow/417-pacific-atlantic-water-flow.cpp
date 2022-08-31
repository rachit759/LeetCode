class Solution {
public:    
    vector<vector<int>> a,p,ans;
    vector<int> dir;
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = size(h), n = size(h[0]);
        a = p = vector<vector<int>> (m, vector<int>(n,0));
        dir = {-1,0,1,0,-1};
        for(int i = 0; i < m; i++) dfs(h,p,i,0), dfs(h,a,i,n-1);
        for(int i = 0; i < n; i++) dfs(h,p,0,i), dfs(h,a,m-1,i);
        
     
        
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &h, vector<vector<int>> &vis, int i, int j) {
        if(vis[i][j]) return;
        vis[i][j] = 1;
        if(a[i][j] == 1 and p[i][j] == 1) ans.push_back(vector<int>{i,j});
        
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
            if(x >= 0 and x < m and y >= 0 and y < n and h[i][j] <= h[x][y])
                dfs(h,vis,x,y);
        }
        
        
    }
    
    
};