class Solution {
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis) {
        vis[src] = 1;
        for(auto node : adj[src]) {
            if(!vis[node]) {
                dfs(node, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination) return true;
        vector<int> adj[n], vis(n,0);
        
        for(auto vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        dfs(source, adj, vis);
        return vis[destination];
    }
};