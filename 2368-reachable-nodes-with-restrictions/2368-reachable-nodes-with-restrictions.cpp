class Solution {
public:
    int count;
    void dfs(int src, vector<int> adj[], vector<int> &vis) {
        vis[src] = 1;
        count += 1;
        
        for(auto node : adj[src]) {
            if(!vis[node]) dfs(node,adj,vis);
        }
        
        return;
    }
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> adj[n];
        vector<int> vis(n,0);
        count = 0;
        
        for(int i = 0; i < n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i < size(restricted); i++) {
            vis[restricted[i]] = 1;
        }
        
        dfs(0,adj,vis);
        return count;
        
    }
};