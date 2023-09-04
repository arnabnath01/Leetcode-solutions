/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
   
        ListNode *d1=head;
        ListNode *d2=head;
 

        while( d2 && d2->next )
        {
            
               d1=d1->next;
            d2=d2->next->next;
             if(d1==d2)
            return true;
         
        }

        return false;
    }
};