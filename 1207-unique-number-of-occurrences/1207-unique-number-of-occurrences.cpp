class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> v(2001,0);
        for(auto i : arr) {
            v[i+1000] += 1;
        }
        
        sort(rbegin(v),rend(v));
        
        for(int i = 1; i < 2001; i++) {
            if(v[i] == 0) return true;
            if(v[i-1] == v[i]) return false;
        }
        
        return true;
        
    } 
};