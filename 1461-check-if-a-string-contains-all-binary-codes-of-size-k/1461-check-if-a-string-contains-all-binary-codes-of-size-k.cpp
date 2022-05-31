class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_map<string,int>  mp;
        
        int n = s.size();
        
        for(int i =0 ;i<=n-k;i++) {
            mp[s.substr(i,k)]++;
        }
        
        //cout<<mp.size();
        
        return mp.size() == (1<<k);
    }
};