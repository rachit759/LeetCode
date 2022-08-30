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
    
    void maker(TreeNode* root, vector<int> adj[]) {
        
        if(root == nullptr) return;
        if(root->left != nullptr) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right != nullptr) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        maker(root->left,adj);
        maker(root->right,adj);  
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        vector<int> adj[100001];
        maker(root,adj);
        
        // for(int i = 1; i < 11; i++) {
        //     cout<<i<<": ";
        //     for(auto it : adj[i]) cout<<it<<" ";
        //     cout<<endl;
        // }
        
        int time = 0;
        queue<int> q;
        q.push(start);
        vector<int> vis(100001,0);
        vis[start] = 1;
        
        while(q.size()) {
            int sz = q.size();
            time += 1;
            while(sz--) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        return time-1;
    }
};