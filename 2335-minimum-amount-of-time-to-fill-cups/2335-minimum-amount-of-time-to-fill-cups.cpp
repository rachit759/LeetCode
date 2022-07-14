class Solution {
public:
    int fillCups(vector<int>& a) {
        
        priority_queue<int> pq(begin(a),end(a));
        
        int second = 0;
        while(pq.top() != 0) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            pq.push(--x);
            pq.push(--y);
            second += 1;
            
            
        }
        
        return second;
        
    }
};