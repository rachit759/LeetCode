class Solution {
public:
    
    vector<int> freq(int n) {
        vector<int> mp(10,0);
        while(n) {
            mp[n%10]++;
            n /= 10;
        }
        return mp;
    }
    
    
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> check = freq(n);
        
        for(int i =0 ; i <= 29; i++) {
            if(check == freq(1<<i)) return true;
        }
        
        return false;
    }
};