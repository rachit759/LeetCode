/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n,-1));
        
        int top = 0, bottom  = m-1, left = 0, right = n-1;
        
        int dir = 0;
        
        while(top <= bottom and left <= right and head) {
            
            if(dir == 0) {
                for(int i = left; i <= right; i++) {
                    if(head) {
                        ans[top][i] = head->val;
                        head = head->next;
                    }
                }
                dir = 1;
                ++top;
            }
            
            else if(dir == 1) {
                for(int i = top; i <= bottom; i++) {
                    if(head) {
                        ans[i][right] = head->val;
                        head = head->next;
                    }
                }
                dir = 2;
                --right;
            }
            else if(dir == 2) {
                for(int i = right; i >= left; i--) {
                    if(head) {
                        ans[bottom][i] = head->val;
                        head = head->next;
                    }
                }
                dir = 3;
                --bottom;
            }
            else {
                for(int i = bottom; i >= top; i--) {
                    if(head) {
                        ans[i][left] = head->val;
                        head = head->next;
                    }
                }
                dir = 0;
                ++left;
            }
            
            
        }
        
        
        
        
        
        
        
        
        
        
        return ans;
        
        
        
        
    }
};