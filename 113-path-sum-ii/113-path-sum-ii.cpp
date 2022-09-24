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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        
        helper(root,target,ans,path,0);
        
        return ans;
        
        
    }
    
    void helper(TreeNode* root, int target,vector<vector<int>> &ans, vector<int> path,int sum) {
         if(!root) return;
        
        if(!root->left and !root->right) {
            if(sum+root->val == target) {
                path.push_back(root->val);
                ans.push_back(path);
            }
            return;
        }
       
        path.push_back(root->val);
        helper(root->left,target,ans,path,sum+root->val);
        helper(root->right,target,ans,path,sum+root->val);

    }
    
};