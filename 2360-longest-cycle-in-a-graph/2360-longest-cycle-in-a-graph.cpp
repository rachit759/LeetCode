class Solution {
public:
    int ans = -1;
    int n;
    void dfs(vector<int> &edges, int src, vector<int> &vis, vector<int>& store) {
        
        if(src == -1) return;
        if(vis[src]) {
        
            int count = -1;
            for(int i = 0; i < size(store); i++) {
                if(store[i] == src) {
                    count = i;
                    break;
                }
            }
            if(count == -1) return;
            ans = max(ans,(int)store.size()-count);
            return;
        }
        
        vis[src] = 1;
        store.push_back(src);
        dfs(edges,edges[src],vis,store);
        
    }
    
    int longestCycle(vector<int>& edges) {
        
        n = (size(edges));
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vector<int> store;
            dfs(edges,i,vis,store);
         }
        
        
        return ans;
        
    }
};