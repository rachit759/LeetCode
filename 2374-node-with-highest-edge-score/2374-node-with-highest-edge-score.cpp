class Solution {
public:
    int edgeScore(vector<int>& edge) {
        
        map<int,long long int>  mp;
        
        for(int i = 0; i < size(edge); i++) {
            mp[edge[i]] += i;
        }
        
        int maxi = INT_MIN;
        int index;
            
        for(auto it : mp) {
            if(it.second > maxi) {
                index = it.first;
                maxi = it.second;
            }
        }
        
        return index;
        
    }
};