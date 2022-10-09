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
class BSTIterator {
    stack <TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse = isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(reverse) pushall(temp->left);
        else pushall(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushall(TreeNode* node) {
        
        while(node) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);    // l for the nextss
        BSTIterator r(root,true);     // r for the beforess
        
        int i = l.next();
        int j = r.next();
        
        while(i < j) {
            if(i + j == k) return true;
            
            if(i + j < k) i = l.next();
            else j = r.next();
            
        }
        
        return false;
    }
};