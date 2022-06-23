class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int> ans;
        vector<int> in(n,0);
        vector<int> adj[n];
        queue<int> q;
        for(auto vec : pre) {
            in[vec[0]]++;
            adj[vec[1]].push_back(vec[0]);
        }
        
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                --in[it];
                if(in[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() != n) return {};
        return ans;
        
    }
};