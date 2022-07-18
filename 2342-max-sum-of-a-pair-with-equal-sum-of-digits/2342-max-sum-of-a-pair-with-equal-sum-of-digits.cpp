class Solution {
public:
    
    int value(int n) {
        int sum  = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int> >  mp;
        for(int i = 0; i < size(nums); i++) {
            mp[value(nums[i])].push_back(nums[i]);
        }
        
        int ans = -1;
        
        for(auto i : mp) {
            vector<int> temp = i.second;
            if(size(temp) > 1) {
                sort(rbegin(temp),rend(temp));
                ans = max(ans, temp[0]+temp[1]);
            }
        }
        
        return ans;
        
    }
};