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
    int res = 0;

    bool parity(vector<int> temp) {
        int count = 0;
        bool even = false;
        for(int a : temp) {
            if(a == 0) continue;
            if(a&1) count += 1;
            if(!(a&1)) even = true;
        }
        if(count == 0 and even) return true;
        return count == 1;
    }
    
    
    int helper(TreeNode* root, vector<int> ans){
        if(!root) return 0;
        ans[root->val]++;
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        if(left == 0 and right == 0) {
            //for(int a : ans) cout<<a<<" ";
            //cout<<endl;
            if(parity(ans)) res += 1;
        }
        return 1;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
    
        if(!root->right and !root->left) return 1;
        vector<int> mp(10,0);
        helper(root,mp);
        return res;
    }
};