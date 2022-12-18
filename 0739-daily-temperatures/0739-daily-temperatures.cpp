class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n(size(temp));
        stack<int> st;
        vector<int> nge(n,0);
        
        for(int i = n-1; i >=0; i--) {
            
            while(!st.empty() and temp[i]>= temp[st.top()])
                st.pop();
            
            if(!st.empty()) nge[i] = st.top() - i;
                
            st.push(i);
        }
        
        return nge;
        
    }
};