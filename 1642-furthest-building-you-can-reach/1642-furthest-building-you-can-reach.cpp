class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        int n(size(h)), i(0);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while(i < n-1) {
            int jump = h[i+1] - h[i];
            if(jump > 0) {
                pq.push(jump);
            }
            
            if(pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            
            if(bricks < 0) return i;
            i++;
        }
        
        return n-1;
        
        
    }
};