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
    unordered_map<int,vector<int>>  adj;
    void maker(TreeNode* root) {
        
        if(root == nullptr) return;
        if(root->left != nullptr) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right != nullptr) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        maker(root->left);
        maker(root->right);  
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        maker(root);
        int time = 0;
        queue<int> q;
        q.push(start);
        unordered_map<int,int>  vis;
        vis[start] = 1;
        while(q.size()) {
            int sz = q.size();
            time += 1;
            while(sz--) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(!vis.count(it)) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        return time-1;
    }
};