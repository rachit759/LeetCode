class Solution {
public:
    vector<string> findAllRecipes(vector<string>& reci, vector<vector<string>>& ing, vector<string>& supp) {
        
        
        int n(size(reci));
        queue<string> q;
        vector<string> ans;
        unordered_map<string,int> indegree;    
        unordered_map<string,vector<string>>  adj;
        
        for(int i = 0; i < n; i++) {
            for(auto ingre : ing[i]) {
                adj[ingre].push_back(reci[i]);
                ++indegree[reci[i]];
            }
        }
        
        for(int i = 0; i < size(supp); i++) {
            q.push(supp[i]);
        }
        
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            for(auto rec : adj[item]) {
                --indegree[rec];
                if(indegree[rec] == 0) {
                    ans.push_back(rec);
                    q.push(rec);
                }
            }
        }
        
        
       return ans;
        
        
    }
};