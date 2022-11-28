class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> mp;
        vector<vector<int>> ans(2);
        
        for(auto vec : matches) {
            
            mp[vec[0]] += 0;
            mp[vec[1]] += 1;
        }
        
        for(auto i : mp) {
            
            if(i.second == 0) ans[0].push_back(i.first);
            else if(i.second == 1) ans[1].push_back(i.first);
        }
        
        return ans;
    }
};