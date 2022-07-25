// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
        
//         int n(size(grid));
        
//         vector<vector<int>> ans = grid;
        
//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
// 	            if(i == j) continue;
//                 swap(grid[i][j],grid[j][i]);
//             }
//         }
        
//         int count = 0;
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
// 	            if(ans[i] == grid[j]) count += 1;
//             }
//         }
        
//         return count;
//     }
// };

// better soln

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        for (const auto& row : grid) {
            rows[row]++;
        }
        
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> col;
            for (int j = 0; j < grid.size(); j++) {
                col.push_back(grid[j][i]);
            }
            ans += rows[col];
        }
        
        return ans;
    }
};