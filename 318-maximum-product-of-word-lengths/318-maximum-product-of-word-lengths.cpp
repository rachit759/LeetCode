class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<vector<int>> v(n, vector<int>(26,0));
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                v[i][words[i][j]-'a'] += 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                //cout<<words[i].size()<<" "<<words[j].size()<<endl;
                int flag = 0;
                for(int k = 0; k < 26; k++) {
                    if(v[i][k] >0 and v[j][k] >0) {flag = 1;}
                }
                
                if(flag == 0) ans = max(ans , (int)words[i].length() * (int)words[j].length());
                
            }
            
        }
        
        
        
        
        
        return ans;
        
    }
};