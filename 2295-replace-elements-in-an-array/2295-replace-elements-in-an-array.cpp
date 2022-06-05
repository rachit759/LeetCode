class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& oper) {
        
        unordered_map<int,int>  mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        int index;
        for(int i = 0; i < oper.size(); i++) {
            index = mp[oper[i][0]];
            mp.erase(oper[i][0]);
            nums[index] = oper[i][1];
            mp[oper[i][1]] = index;
        }
        
        return nums;
        
    }
};