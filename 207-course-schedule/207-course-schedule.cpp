class Solution {
public:
    bool checker(int node, vector<int> adj[] , vector<int> &vis, vector<int> &dfsvis) {
        
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checker(it,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int> vis(n,0), dfsvis(n,0);
        
        vector<int> adj[n];
        
        for(auto vec : pre) adj[vec[1]].push_back(vec[0]);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(checker(i,adj,vis,dfsvis)) return false;
            }
            
        }
        
        return true;
    }
};