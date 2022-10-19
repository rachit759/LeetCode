class compare{
public:
    bool operator()(const pair<int,string> &a, const pair<int,string> &b){
        
        int x = a.first;
        int y = b.first;
        
        if(x != y) return x > y; 
        
        return a.second < b.second; 
        
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(auto i : words) ++mp[i];
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> minheap;
        
        for(auto i : mp) {
            
            minheap.push({i.second,i.first});
            
            if(minheap.size() > k) minheap.pop();
        }
        
        
        vector<string> ans(k);
        int i = k-1;
        while(!minheap.empty()){
            ans[i--] = minheap.top().second;
            minheap.pop();
        }
        
        return ans;
        
    }
};