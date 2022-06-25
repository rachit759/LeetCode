#define ll long long 
#define mod 1e9+7
#define pb push_back
#define all(x) (x).begin(),(x).end() 

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        
        long long sum = accumulate(begin(nums), end(nums), 0LL);
        priority_queue<ll> pq(begin(nums), end(nums));
      
        while(pq.size()) {
            ll maxele = pq.top();
            ll remsum = sum - maxele;
            pq.pop();
            
            if(maxele == 1 or remsum == 1) return 1;
            if(remsum == 0 or remsum > maxele) return 0;
            
            ll updatedmax = maxele % remsum;
            if(updatedmax == 0) return 0;
            sum = remsum + updatedmax;
            pq.push(updatedmax);
            
        }
        return 1;
    }
};