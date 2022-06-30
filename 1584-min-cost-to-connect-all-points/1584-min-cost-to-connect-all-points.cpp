#define ll long long 
#define mod 1e9+7
#define pb push_back
#define all(x) (x).begin(),(x).end() 
#define pi pair<int,int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        int n(size(p)), cost(0),rem(0);
        priority_queue<pi, vector<pi>, greater<pi>> pq;  // weight,node
        vector<int> mst(n,0);
        pq.push({0,0});
        
        while(rem < n) {
            int currnode = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(mst[currnode]) continue;
            mst[currnode] = 1;
            cost += weight;
            ++rem;
            for(int j = 0; j < n; j++) {
                if(!mst[j]) {
                    int nextWeight = abs(p[currnode][0] - p[j][0]) + 
                                     abs(p[currnode][1] - p[j][1]);
                    
                    pq.push({nextWeight,j});
                }
            }
        }
        
        return cost;
        
    }
};