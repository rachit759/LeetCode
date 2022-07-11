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
    void reversepreorder(TreeNode* node, int level, vector<int> &ans)
    {
        if(node == nullptr) return ;
        
        if(ans.size() == level) ans.push_back(node->val);
        
        if(node->right) reversepreorder(node->right,level+1, ans);
        if(node->left) reversepreorder(node->left,level+1, ans);
        
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        
        reversepreorder(root,0,ans);
        return ans;
        
    }
};