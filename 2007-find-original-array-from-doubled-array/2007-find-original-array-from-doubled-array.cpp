class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
        
        int n = nums.size();
        if(n&1) return {};
        vector<int>  ans;
        map<int,int>  mp;   // number, freq
        
        for(int a : nums) ++mp[a];
        
        for(auto &i : mp) {
            if(i.first == 0) {
                if(i.second % 2 == 0) {
                    i.second /= 2;
                    while(i.second--) ans.push_back(0);
                }
                else return {};
            } 
            else if(mp.count(i.first*2) and i.second <= mp[i.first*2]) {
                    mp[i.first*2] -= i.second;
                    if(mp[i.first*2] == 0) mp.erase(i.first*2);
                    while(i.second--) ans.push_back(i.first);
            }
            else return {};
        }
        
        return ans;
    }
};