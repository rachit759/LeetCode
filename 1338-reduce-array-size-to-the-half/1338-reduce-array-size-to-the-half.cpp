class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n(size(arr)), count(0), take(0);
        vector<int> mp(100001);
        
        for(auto it :arr) mp[it]++;
        
        sort(rbegin(mp),rend(mp));
        
        for(int i=0; i <= 100000; i++) {
            if(take < n/2) {
                take += mp[i];
                count += 1;
            }
            else break;
        }
        
        return count;
    }
};