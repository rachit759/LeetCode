class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;
        
        for(auto i : s) ++mp[i];
        
        
        priority_queue<pair<int,char>> maxheap;
        
        for(auto i : mp) {
            maxheap.push({i.second,i.first});
        }
        
        string p;
        
        while(!maxheap.empty()) {
            auto i = maxheap.top();
            maxheap.pop();
            
            string t(i.first,i.second);
            p += t;
            
        }
        
        return p;
        
        
    }
};