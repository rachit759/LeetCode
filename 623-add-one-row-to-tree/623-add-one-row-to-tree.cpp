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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {
            TreeNode* newroot  = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        int flag;
        while(q.size()) {
            int sz = q.size();
            flag = 0;
            while(sz--) {
                auto node = q.front();
                q.pop();
                if(d == depth-1) {
                    flag = 1; 
                    auto left = node->left;
                    auto right = node->right;
                    TreeNode* newleft = new TreeNode(val);
                    TreeNode* newright = new TreeNode(val);
                    node->left = newleft;
                    node->right = newright;
                    newleft->left = left;
                    newright->right = right;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag == 1) return root;
            d += 1;
        }
        
        
        
        return root;
    }
};