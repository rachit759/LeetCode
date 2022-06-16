class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n(size(nums));
        vector<pair<int,int>> v; // element, list
        for(int i = 0; i < n; i++) {
            for(auto ele : nums[i]) {
                v.push_back({ele,i});
            }
        }
        sort(begin(v),end(v));
        
        vector<int> ans,mp(n,0);
        int i(0), j(0), k(0);
        
        while(j < size(v)) {
            if(++mp[v[j].second] == 1) ++k;
            if(k == n) {
                while(mp[v[i].second] > 1) {
                    --mp[v[i++].second];
                }
                if(ans.empty() or ans[1]-ans[0] > v[j].first-v[i].first) {
                    ans = vector<int>{v[i].first,v[j].first};
                }
            }
            j++;
        }
        
        return ans;
        
    }
};