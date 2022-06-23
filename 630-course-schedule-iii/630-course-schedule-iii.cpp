class Solution {
public:
    int scheduleCourse(vector<vector<int>>&c) {
    
        sort(begin(c),end(c),[](vector<int> &a , vector<int> &b){ return a[1] < b[1];});
        
        
        int time  =0;
        //int count =0;
        
        int n = c.size();
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++) {
            if(time+c[i][0] <= c[i][1]) {
                time += c[i][0];
                pq.push(c[i][0]);
                //count+=1;
            }
            else if(pq.size() and pq.top() > c[i][0]) {
                time -= pq.top();
                time += c[i][0];
                pq.pop();
                pq.push(c[i][0]);
            }
            
        } 
       
        return pq.size();
        
    }
};