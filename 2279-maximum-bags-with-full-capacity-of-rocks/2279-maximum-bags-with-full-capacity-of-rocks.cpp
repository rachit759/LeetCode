class Solution {
public:
    bool static compare(const pair<int,int> &a , const pair<int,int> &b) {
        return a.first-a.second < b.first-b.second;
    }
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        
        int n  = rocks.size();
        vector<pair<int,int>> nums;
        for(int i = 0; i < n; i++) {
            nums.push_back({capacity[i],rocks[i]});
        }
        
        sort(begin(nums),end(nums),compare);
        
        int count = 0;
        
        
        
        for(auto [a,b] : nums) {
            cout<<a<<" "<<b<<endl;
            if(a == b) count += 1;
        }
        
        for(auto [a,b] : nums) {
            if(ar == 0) break;
            else if(a==b) continue;
            else {
                if(b + ar >= a) {
                    count+=1;
                    ar -= (a-b);
                }
            }
        }
        
        return count;
        
    }
};