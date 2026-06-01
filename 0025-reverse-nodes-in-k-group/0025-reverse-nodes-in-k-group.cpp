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
    ListNode* reverseSegment(ListNode*head,ListNode*endNext){
        ListNode* prev=endNext;
        ListNode* curr=head;

        while(curr!=endNext){
            //Save the next node
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev; //it will be the new head
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //dummy object
        ListNode dummy(0);
        dummy.next=head;

        ListNode* groupPrev=&dummy;

        while(true){
            //Find the kth value
            ListNode* kth=groupPrev;
            for(int i=0;i<k;i++){
                kth=kth->next;

                if(kth==NULL){
                    return dummy.next;
                }
            }
            //Node after current group
            ListNode* groupNext=kth->next;
            //first node of current group
            ListNode* groupStart=groupPrev->next;

            //reverse the current group
            ListNode* newGroupHead=reverseSegment(groupStart,groupNext);
            //old head becomes tail
            ListNode* newGroupTail=groupStart;
            //connect the previous part to reversed part
            groupPrev->next=newGroupHead;

            //connect tail to next group
            newGroupTail->next=groupNext;

            //Move to next group
            groupPrev=newGroupTail;
        }
    }
};