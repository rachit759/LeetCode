class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
       
        vector<pair<int,int>> v;
        
        for(int i = 0; i < grow.size(); i++) v.push_back({grow[i],plant[i]});
        
        sort(rbegin(v),rend(v));
        
        int total = 0, curr = 0;
        
        for(auto [g,p] : v) {
            total = max(total , curr + g + p);
            curr += p;
        }
        
        return total;
        
    }
};


// read discussion