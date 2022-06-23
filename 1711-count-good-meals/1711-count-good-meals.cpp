#define ll long long 
#define mod 1e9+7
#define pb push_back
#define all(x) (x).begin(),(x).end() 

class Solution {
public:
    int countPairs(vector<int>& deli) {
        
        int res(0);
        unordered_map<int,int>  mp;
        
        for(auto num : deli) {
            for(int i = 0;i < 22; i++) {
                int target = (1<<i) - num;
                if(mp.find(target) != mp.end()) {
                    res += mp[target];
                    res %= (int)mod;
                }
            }
            mp[num] += 1;
        }
        
        return res;
        
    }
};