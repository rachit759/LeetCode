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
class Solution {
public:
    
    int helper(TreeNode* root) {
        if(!root) return 0;
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        if(left == 0 and right == 0) {
            root->left = nullptr;
            root->right = nullptr;
            return root->val;
        }
        else if(left == 0 and right == 1) {
            root->left = nullptr;
            return 1;
        }
        else if(left == 1 and right == 0) {
            root->right = nullptr;
            return 1;
        }
        
        return 1;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        int p = helper(root);
        if(p == 0) return nullptr;
        return root;
    }
};