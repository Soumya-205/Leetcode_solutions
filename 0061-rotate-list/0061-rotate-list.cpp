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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        //FIND THE LENGTH OF THE LIST
        int n=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        //Reduce k
        k=k%n;
        if(k==0){
            return head;
        }
        //Make the list Circular
        tail->next=head;
        int steps=n-k;

        ListNode* newTail=tail;
        while(steps--){
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;

        //Break the circle
        newTail->next=NULL;

        return newHead;
    }
};