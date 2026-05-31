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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        //create a dummy node for easy insertion
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;

        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                tail->next=head1;
                head1=head1->next;
            }else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        //if head1 ele is still left and head2 is null
        if(head1!=NULL){
            tail->next=head1;
        }
        //if head2 ele are still left and head1 is null
        if(head2!=NULL){
            tail->next=head2;
        }
        return dummy->next;

        
    }
};