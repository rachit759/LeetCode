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
    
    ListNode* reverselist(ListNode* head)
    {
          ListNode* prev = nullptr;
          ListNode* curr = head;
          ListNode* temp = nullptr;
          while(curr)
          {
              temp = curr->next;
              curr->next = prev;
              prev = curr;
              curr = temp;
          }
         return prev;     
    }
    
    
    
    
    bool isPalindrome(ListNode* head) {
        
        if(!head or !head->next)
            return 1;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverselist(slow->next);
        slow = slow->next;
        
        while(slow)
        {
            if(slow->val!=head->val)
                return 0;
            slow = slow->next;
            head = head->next;
        }
        
        return 1;
        
  
        
    }
};