class Solution {
public:
    
    void dfs(int src, vector<int> &vis, vector<int> adj[]) {
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it]) {
                dfs(it,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& con) {
        
        
        int n(size(con));
        
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(con[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count += 1;
                dfs(i,vis,adj);
            }
        }
        
        return count;
        
        
    }
};