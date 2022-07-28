class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        vector<int> adj[n];
        vector<int> in(n,0);
        
        for(auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
            in[v[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(in[i] == 1) q.push(i);
        }
        
        vector<int> ans;
        while(size(q)) {
            
            int sz = size(q);
            ans.clear();
            while(sz--) {
                int t = q.front();
                ans.push_back(t);
                q.pop();
                for(auto node : adj[t]) {
                    if(--in[node] == 1) q.push(node);
                }
            }
        }
        
        return ans;
        
        
    }
};