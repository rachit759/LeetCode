class Solution {
public:
    int longestValidParentheses(string s) {
	int MAX = 0;  
	stack<int> st;
	st.push(-1); 
        
	for(int i = 0; i < size(s); i++)
		if(s[i] == '(') st.push(i);            
		else{                
			st.pop();
			if(st.empty()) st.push(i);
			else MAX = max(MAX, i - st.top());
		}        
	return MAX;
}
};