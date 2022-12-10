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
    long total, ans = 0;
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root);
        return (int)(ans % 1000000007);
    }
    
    long dfs(TreeNode* root) {
        if(!root) return 0;
        long left = dfs(root->left);
        long right = dfs(root->right);
        long subtree = left + right + root->val;
        ans = max(ans, (total-subtree) * subtree);
        return subtree;
    }
    
    // void sum(TreeNode* root) {
    //     if(!root) return;
    //     sum(root->left);
    //     total += root->val;
    //     sum(root->right);
    // }
    
};