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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int count =0;
//         ListNode* ptr= head;
//         while(ptr)
//         {
//             count+=1;
//             ptr=ptr->next;
//         }
        
//         if(count == 1)
//         {
//             head = nullptr;
//             return head;
//         }
//         if(count == n)
//         {
//             head=head->next;
//             return head;
//         }
//         count = count - n -1;
        
//         ListNode* curr = head;
        
//         while(count--)
//         {
//             curr= curr->next;
//         }
//         curr->next = curr->next->next;
        
//         return head;
        
//     }
// };





class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
      ListNode* start = new ListNode();
      start->next=head;
        
      ListNode* slow = start;
      ListNode* fast = start;
        
      for(int i=0;i<n;i++)   // fast and slow pointers
          fast=fast->next;
        
      while(fast->next)
      {
          slow=slow->next;
          fast=fast->next;
      }
       slow->next=slow->next->next;
        
        return start->next;
     
    }
};


































