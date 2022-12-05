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
/*class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
       totoise and hare method 
       slow pointer and fast pointer
 ListNode *slow = head , *fast = head;
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};*/

//brute count the elements int the ll

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
       
        int count =0;
        ListNode* ptr = head;
        
        while(ptr)
        {
            count+=1;
            ptr=ptr->next;
        }
        
        count /=2;
        //cout<<count<<" ";
        ListNode* temp = head;
        
        while(count--)
        {
            temp = temp->next;
            
        }
        
        return temp;
        
   
        
    }
};
