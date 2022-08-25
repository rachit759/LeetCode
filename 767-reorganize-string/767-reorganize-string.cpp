class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int>  mp;
                
        for(auto i : s) ++mp[i];
        
        priority_queue<pair<int,char>> pq;
        
        for(auto [i,j] : mp) pq.push({j,i});
        
        string res;
    
        while(pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            res += p1.second;
            res += p2.second;
            if(--p1.first) pq.push({p1.first,p1.second});
            if(--p2.first) pq.push({p2.first,p2.second});
        }
        
        
        if(pq.size()) {
            if(pq.top().first > 1) return "";
            else res += pq.top().second;
        }
        
        return res;
        
    }
};