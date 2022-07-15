class Solution {
public:

    // false means cycle
    bool checker(int node, vector<vector<int>> &graph,vector<int> &vis, vector<int> &dfs, vector<int> &safe) {
        vis[node] = 1;
        dfs[node] = 1;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(checker(it,graph,vis,dfs,safe) == false)
                return safe[node] = false;
            }
            else if(dfs[it]) {
                return safe[node] = false;
            }
        }
        dfs[node] = 0;
        return safe[node];
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> dfs(n,0), vis(n,0), safe(n,1), ans;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) checker(i,graph,vis,dfs,safe);
        }
        
        for(int i = 0; i < n; i++) {
            if(safe[i]) ans.push_back(i);
        }
        
        return ans;
        
    }
};