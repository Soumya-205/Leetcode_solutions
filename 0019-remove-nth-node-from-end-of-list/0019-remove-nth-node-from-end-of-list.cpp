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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next=head;

        ListNode* slow=&dummy;
        ListNode* fast=&dummy;
        //move fast to n+1 node
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        //Move both the pointer
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        //delete the nth node from the end
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;

        return dummy.next;
    }
};