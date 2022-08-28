class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        
        
        int time = 0;
        int n = g.size();
        vector<vector<int>> ans(n, vector<int>(3,0));
        
        for(int i = 0; i < n; i++) {
            for(auto c : g[i]) {
                if(c == 'G') ans[i][0]++;
                else if(c == 'P') ans[i][1]++;
                else ans[i][2]++;
            }
        }
        
        int G,P,M;        
        G = P = M = 0;
        
        for(int i = 0; i < n; i++) {
            if(ans[i][0] > 0) G = i;
            if(ans[i][1] > 0) P = i;
            if(ans[i][2] > 0) M = i;  
        }
                
        for(int i = 0; i < n; i++) {
            if(i <= G ) {
                time += ans[i][0];
                if(i != n-1 and i < G) time += t[i];
            }
            if(i <= P ) {
                time += ans[i][1];
                if(i != n-1 and i < P) time += t[i];
            }
            if(i <= M ) {
                time += ans[i][2];
                if(i != n-1 and i < M) time += t[i];
            }
        }
        
        return time;
        
    }
};