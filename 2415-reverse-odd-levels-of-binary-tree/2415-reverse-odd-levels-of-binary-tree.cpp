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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        int level = 0;
        queue<TreeNode*> qnode;
        queue<TreeNode*> qvalue;
        
        qnode.push(root);
        
        
        while(qnode.size()) {
            int sz = qnode.size();
            vector<int> v;
            while(sz--) {
                TreeNode* node = qnode.front();
                qvalue.push(node);
                qnode.pop();
                v.push_back(node->val);
                if(node->left){qnode.push(node->left);
                qnode.push(node->right);}
            }
            
            if(level%2) reverse(begin(v),end(v));
            int i =0;
            while(qvalue.size()) {
                auto n = qvalue.front();
                qvalue.pop();
                n->val = v[i++];
            }
            level += 1;
        }
        
        return root;
        
    }
};