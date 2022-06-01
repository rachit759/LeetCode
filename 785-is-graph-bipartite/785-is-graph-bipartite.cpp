class Solution {
public:
    
    bool checkbipartite(int start, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
    
    
    bool checker(int n, vector<int> adj[]) {
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(checkbipartite(i,adj,color) == false) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            adj[i] = graph[i];
        }
        
        return checker(n,adj);
        
        
    }
};