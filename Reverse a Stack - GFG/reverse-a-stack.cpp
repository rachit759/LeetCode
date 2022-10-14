//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insert(stack<int> &st, int ele) {
        if(st.size() == 0) {
            st.push(ele);
        }
        else {
            int t = st.top();
            st.pop();
            insert(st,ele);
            st.push(t); 
        }
        
    }

    void reverse(stack<int> &st) {
        if(st.size()) {
            int t = st.top();
            st.pop();
            reverse(st);
            insert(st,t);
        }
        return;
    }
    
    
    
    stack<int> Reverse(stack<int> st){
       reverse(st);
        return st;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends