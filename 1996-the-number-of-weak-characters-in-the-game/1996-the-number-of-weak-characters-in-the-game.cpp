class Solution { 
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        
        sort(begin(pro),end(pro), [](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        stack<pair<int,int>> st;  
        int ans = 0;
        for(int i = 0; i < pro.size(); i++) {
            while(st.size() and st.top().first < pro[i][0] and st.top().second < pro[i][1]) {
                ans += 1;
                st.pop();
            }
            st.push({pro[i][0],pro[i][1]});      
        }
        return ans;
    }
};