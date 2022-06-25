class Solution {
public:   
    void DFS(int node, vector<int> adj[],vector<int> &vis, int &count) {
        vis[node] = 1;
        ++count;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                DFS(it, adj, vis, count); 
            }
        }
}
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long int ans(0) , sum(0);
        vector<int> vis(n,0);
        
        vector<int> adj[n];
        for(auto vec : edges) {
            adj[vec[1]].push_back(vec[0]);
            adj[vec[0]].push_back(vec[1]);
        }
        int count;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int count(0);
                DFS(i,adj,vis,count);
                ans += count*sum;
                sum += count;
            }
        }   

        return ans;
    }
};