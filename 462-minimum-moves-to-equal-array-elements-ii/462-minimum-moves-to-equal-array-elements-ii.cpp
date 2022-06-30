class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // median calculation 
        
        sort(begin(nums),end(nums));
        int moves = 0, n = nums.size();
        for(int i = 0; i < n/2; i++) {
            moves += nums[n-i-1]- nums[i];
        }
        
        return moves;
    }
};