// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[S] = 0;
        pq.push({0,S});
        
//         for(auto vec2d : adj[0]) {
                
//                     cout<<vec2d[0]<<" "<<vec2d[1]<<endl;
//                 }
            
        
// cout<<endl;
        while(!pq.empty()) {
            int prev = pq.top().second;                        //vec[0] node
            int distprev = pq.top().first;                     // vec[1] dist
            pq.pop();
            for(auto vec : adj[prev]) {
                int next = vec[0];
                int nextdist = vec[1];
                if(distprev + nextdist < dist[next]) {
                    dist[next] = distprev + nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
        
        return dist;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends