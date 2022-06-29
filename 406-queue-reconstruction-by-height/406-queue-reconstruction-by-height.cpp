class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& nums) {
        
        vector<vector<int>> ans;
        sort(begin(nums),end(nums),[](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        for(int i = 0; i < nums.size(); i++) {
            ans.insert(ans.begin() + nums[i][1], nums[i]);
        }
        
        return ans;
        
        
    }
};