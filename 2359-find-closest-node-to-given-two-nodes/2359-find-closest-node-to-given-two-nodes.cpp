class Solution {
public:
    vector<int> bfs(int src, vector<int> &edges) {
        vector<int> dist(edges.size(),INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(edges[node] != -1 and dist[node] + 1 < dist[edges[node]]) {
                dist[edges[node]] = dist[node] + 1;
                q.push(edges[node]); 
            }
        }
        return dist;
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        vector<int> d1 = bfs(node1, edges);
        vector<int> d2 = bfs(node2, edges);
        
        int res = INT_MAX;
        int ans = -1;
        
        for(int i = 0; i < size(edges); i++) {
            if(d1[i] != INT_MAX and d2[i] != INT_MAX and res > max(d1[i],d2[i])) {
                res = max(d1[i], d2[i]);
                ans = i;
            }
        }   
        
        return ans;
        
    }
};