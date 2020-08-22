/*
 Reorder List

Solution
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
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
        
    ListNode* reverse(ListNode* node)
    {
            if(node==NULL)
                    return NULL;
            ListNode* prev = NULL;
            ListNode* curr = node;
            ListNode* next = node->next;
            while(curr!=NULL)
            {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
            }
            
            return prev;
    }
        
    void merge(ListNode* l1,ListNode* l2)
    {
            while(l2!=NULL)
            {
                   ListNode* next = l1->next;
                   l1->next = l2;
                   l1 = l2;
                   l2 = next; 
            }
            
    }
public:
    void reorderList(ListNode* head) {
            if(head==NULL || head->next==NULL)
            {
                    return;
            }
            
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = head;
            while(fast!=NULL && fast->next!=NULL)
            {
                    prev = slow;
                    slow = slow->next;
                    fast = fast->next->next;
            }
            
            prev->next = NULL;
            ListNode* l1 = head;
            ListNode* l2 = reverse(slow);
            merge(l1,l2);
            
            
        
    }
};