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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right){
            return head;
        }
        ListNode dummy(0);
        dummy.next=head;

        ListNode* prev=&dummy;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* start=prev->next;
        ListNode* curr=start;
        ListNode* prevRev=NULL;

        for(int i=left;i<=right;i++){
            ListNode* nextNode=curr->next;
            curr->next=prevRev;
            prevRev=curr;
            curr=nextNode;
        }
        prev->next=prevRev;
        start->next=curr;

        return dummy.next;
        
    }
};