class Solution {
public:
    int edgeScore(vector<int>& edge) {
        
        unordered_map<int,long long int>  mp;
        
        for(int i = 0; i < size(edge); i++) {
            mp[edge[i]] += i;
        }
        
        int maxi = INT_MIN;
        int index = INT_MAX;
            
        for(auto it : mp) {
            if(it.second > maxi) {
                index = it.first;
                maxi = it.second;
            }
            else if(it.second == maxi and it.first < index) {
                index = it.first;
            }
        }
        
        return index;
        
    }
};