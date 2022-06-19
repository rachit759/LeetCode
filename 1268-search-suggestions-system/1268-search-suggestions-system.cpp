class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        
        int k = search.size();
        int n = products.size();
        
        unordered_map<string,vector<string>>  mp;
        sort(begin(products),end(products));
        
        
		// for(auto i : products) {
		// cout<<i<<" ";
		// }
        
        for(int i = 0; i < n; i++) {
            string word = products[i];
            int sz= min(k,(int)word.size());
            for(int j = 1; j <= sz; j++) {
                string p = word.substr(0,j);
                mp[p].push_back(word);
            }
            
        }
        
        vector<vector<string>> ans;
        
        for(int i = 1; i <= k; i++) {
            vector<string> res;
            string p = search.substr(0,i);
            
            vector<string> s = mp[p];
            //sort(begin(s),end(s));
            int sz = min((int)s.size(),3);
            
            for(int j = 0; j < sz; j++) res.push_back(s[j]);
            
            ans.push_back(res);
         
        }
        
        
        
        return ans;
        
    }
};