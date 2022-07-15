#define pi pair<int,int>

class c1{
  public:
  bool operator()(pair<int,int>&a, pair<int,int>&b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  }
};

class c2{
  public:
  bool operator()(pair<int,int>&a, pair<int,int>&b){
    return a.first > b.first;
  }
};



class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        
        priority_queue<pi, vector<pi>, c1> free;       // weight index
        priority_queue<pi , vector<pi>, c2> used;  // time index
        
        int n = size(t);
        for(int i = 0; i < size(s); i++) {
            free.push({s[i],i});
        }
        
        int time = 0;
        vector<int> res(n);
        
        for(int i = 0; i < n; i++) {
            
            time = max(time,i);
            
            if(!size(free)) time = max(time,used.top().first);
           
            while(used.size() and used.top().first <= time) {
                auto it = used.top(); 
                used.pop();
                free.push({s[it.second], it.second});
            } 
            
            auto it = free.top(); free.pop();
            res[i] = it.second;
            used.push({time + t[i], res[i]});
            
            
        }
        
        
        return res;
        
        
    }
};