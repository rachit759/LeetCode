class Solution {
public:
    
    void dfs(int src, vector<int> adj[], vector<int> &vis) {
        
        vis[src] = 1;
        
        for(auto node : adj[src]) {
            if(!vis[node]) dfs(node,adj,vis);
        }
        
        
    }
    
    

    
    int makeConnected(int n, vector<vector<int>>& con) {
        
        int m(size(con)), components(0);
        
        if(m < n-1) return -1;
        
        vector<int> vis(n,0);
        vector<int> adj[n];
        
        for(auto vec : con) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i,adj,vis);
                components += 1;
            }
        }
        
        
        return components-1;
        
        
    }
};