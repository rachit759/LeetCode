#define ll long long 
#define mod 1e9+7
#define pb push_back
#define all(x) (x).begin(),(x).end() 
#define pi pair<int,int>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pi> adj[n];
        for(auto vec : flights) adj[vec[0]].push_back({vec[1],vec[2]});

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;     // cost, current, hops;  // minheap
        pq.push({0,src,0});
        vector<int> stops(n,INT_MAX);
        
        while(pq.size()) {
            auto node = pq.top();
            pq.pop();
            
            int cost = node[0];
            int curr = node[1];
            int stop = node[2];
            
            if(curr == dst) return cost;
            if(stop > k) continue;
            if(stops[curr] != INT_MAX and stops[curr] <= stop) continue;
            stops[curr] = stop;
            for(auto vec : adj[curr]) {
                pq.push({cost+vec.second,vec.first,stop+1});
            }
        }
        
        return -1;
    }
};