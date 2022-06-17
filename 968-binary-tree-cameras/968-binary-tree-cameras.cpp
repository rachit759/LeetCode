/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define nocamera 1
#define noneed 2
#define hascamera 3

class Solution {
public:
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == nocamera) ++ans;
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return noneed;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == nocamera or right == nocamera) {
            ++ans;
            return hascamera;
        }
        else if(left == hascamera or right == hascamera) {
            return noneed;
        }
        else return nocamera;
    }
    
    
};