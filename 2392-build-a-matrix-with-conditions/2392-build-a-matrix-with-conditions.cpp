class Solution {
public:
    
    vector<int> topo(int n, vector<vector<int>> r) {
        
        vector<int> adj[n+1];
        vector<int> in(n+1,0);
        
        for(auto vec : r) {
            adj[vec[0]].push_back(vec[1]);
            ++in[vec[1]];
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i = 1; i <= n; i++) 
            if(in[i] == 0) q.push(i);
     
        while(q.size()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]) {
                if(--in[it] == 0) q.push(it);
            }
        }
        return topo;
    }
    
    
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        
        vector<vector<int>> ans(k, vector<int>(k,0));
        
        vector<int> row  = topo(k,r);
        if(row.size() != k) return {};
        
        vector<int> col  = topo(k,c);
        if(col.size() != k) return {};
        
        vector<int> idx(k+1,0);
        
        for(int i = 0; i < k; i++) {
            idx[row[i]] = i;
        }
        
        for(int i = 0; i < k; i++) {
            ans[idx[col[i]]][i] = col[i];
        }
        
        return ans;
        
    }
};