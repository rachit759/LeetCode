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
            if(edges[node] != -1) {
                if(dist[node] + 1 < dist[edges[node]]) {
                    dist[edges[node]] = dist[node] + 1;
                    q.push(edges[node]);
                }
            }
        }
        
        return dist;
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        
        vector<int> d1 = bfs(node1, edges);
        vector<int> d2 = bfs(node2, edges);
        
        int dis = INT_MAX;
        int ans;
        
        for(int i = 0; i < size(edges); i++) {
            int temp = INT_MAX;
            if(d1[i] != INT_MAX and d2[i] != INT_MAX) {
                temp = max(d1[i],d2[i]); 
                if(temp < dis) {
                dis  = temp;
                ans = i;
                }
            }
        }   
        
        return dis == INT_MAX ? -1 : ans;
        
        
    }
};