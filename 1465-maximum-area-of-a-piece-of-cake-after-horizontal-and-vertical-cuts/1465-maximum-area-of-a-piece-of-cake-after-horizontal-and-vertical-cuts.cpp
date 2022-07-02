#define ll long long 
//#define mod 1e9+7
#define pb push_back
#define all(x) (x).begin(),(x).end() 

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        long long int mod = 1000000007;
        sort(begin(hc),end(hc));
        sort(begin(vc),end(vc));
        
        //long long int ans;
        vector<int> a,b;
        
        a.push_back(hc[0]);
        for(int i = 1; i < hc.size(); i++) {
            a.push_back(hc[i]-hc[i-1]);
        }
        a.push_back(h-hc[size(hc)-1]);
            
        
        b.push_back(vc[0]);
        for(int i = 1; i < vc.size(); i++) {
            b.push_back(vc[i]-vc[i-1]);
        }
        b.push_back(w-vc[size(vc)-1]);
        
        //for(auto i : b) cout<<i<<" ";
        
        
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        
         long long int a1 = *max_element(a.begin(),a.end());
        long long int b1 = *max_element(b.begin(), b.end());
        
        // Multiply and return
        return (int)(a1%mod*b1%mod);
        
        //return (int)ans ;
        
    }
};