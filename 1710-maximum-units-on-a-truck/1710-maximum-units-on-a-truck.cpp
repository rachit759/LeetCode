class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truck) {
        
        int units = 0;
        int boxes = 0;
        
        sort(begin(nums),end(nums), [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });
        
        for(int i = 0; i < nums.size(); i++) {
            if(boxes + nums[i][0] <= truck) {
                units += nums[i][0]*nums[i][1];
                boxes += nums[i][0];
            }
            else {
                int take = truck-boxes;
                if(take > 0) units += take*nums[i][1];
                break;
            }
        }
        
        return units;
    }
};