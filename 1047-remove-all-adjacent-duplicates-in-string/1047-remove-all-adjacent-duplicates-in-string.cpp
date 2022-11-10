class Solution {
public:
    string removeDuplicates(string &s) {
        
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(!st.size()) {
                st.push(s[i]);
            }
            else {
                if(st.top() == s[i]) {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        s.clear();
        while(st.size()) {
            s += st.top();
            st.pop();
        }
        reverse(begin(s),end(s));
        return s;
    }
};