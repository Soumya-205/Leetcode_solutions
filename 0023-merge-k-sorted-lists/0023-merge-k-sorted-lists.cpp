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
    ListNode* merge2lists(ListNode* L1,ListNode* L2){
        ListNode dummy(0);
        ListNode* tail=&dummy;

        while(L1!=NULL && L2!=NULL){
            if(L1->val<=L2->val){
                tail->next=L1;
                L1=L1->next;
            }else{
                tail->next=L2;
                L2=L2->next;
            }
            tail=tail->next;
        }
        if(L1!=NULL){
            tail->next=L1;
        }
        if(L2!=NULL){
            tail->next=L2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* result=lists[0];
        for(int i=1;i<lists.size();i++){
            result=merge2lists(result,lists[i]);
        }
        return result;
    }
};