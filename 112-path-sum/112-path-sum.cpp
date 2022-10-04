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
    bool flag =0;
    bool hasPathSum(TreeNode* root, int target) {
        path(root,0,target);
        
        return flag;
    }
    
    void path(TreeNode* root,int sum , int target) {
        
        if(root and root->left ==nullptr  and root->right==nullptr) {
            if(sum+root->val == target) flag = 1;
        }
        
        if(!root){
            return ;
        }
        path(root->left , sum+root->val,target);
        path(root->right, sum+root->val, target);
    
    }
    
    
};