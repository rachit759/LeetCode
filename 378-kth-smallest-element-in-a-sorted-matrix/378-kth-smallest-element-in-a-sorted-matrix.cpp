class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        
        int n(size(mat)), low(mat[0][0]), high(mat[n-1][n-1]), mid;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            int count = 0;
            for(int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin(); 
            }
            
            if(count < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
        
    }
};