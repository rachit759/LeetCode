/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            vector<int> row;
            for(int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                row.push_back(node->val);
                for(auto child : node->children) q.push(child);
            }
            ans.push_back(row);
        }
       return ans;   
    }
};