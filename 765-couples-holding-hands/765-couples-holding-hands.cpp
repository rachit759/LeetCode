class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        
        for(auto &i : row) {           // making couples equal
            if(i & 1) --i;
        }
        
        int n(size(row)), swaps(0);
        
        for(int i = 0; i < n-1; i += 2) {
            if(row[i] == row[i+1]) continue;
            
            int j = i+2;
            
            while(j < n) {
                if(row[i] == row[j]) break;
                j++;
            }
            swaps += 1;
            swap(row[i+1], row[j]);
        }
        
        
        return swaps;
        
    }
};