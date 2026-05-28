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
    ListNode* reverseList(ListNode* head) {
       
       //previous Node
       ListNode* prev=NULL;
       //current node
       ListNode* curr=head;

       //traverse the list
       while(curr!=NULL){
        //save the next node
        ListNode* nextNode=curr->next;
        //reverse the pointer
        curr->next=prev;
        //move prev forward
        prev=curr;
        //move the current forward
        curr=nextNode;
       }
       return prev;
    }
};