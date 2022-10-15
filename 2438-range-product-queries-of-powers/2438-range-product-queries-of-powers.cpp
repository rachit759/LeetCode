class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        
        int m = 1000000007;
        vector<int> v, ans;
        for(int i = 0; i < 32; i++) {
            if(n & (1<<i)) {
                v.push_back(1<<i);
            }
        }
        
        long long prod;
        for(auto vec : q) {
            prod = 1;
            for(int i = vec[0]; i <= vec[1]; i++) {
                prod = (prod * v[i]) % m;
                prod %= m;
            }
            ans.push_back(prod);
        }
        
        return ans;
    }
};