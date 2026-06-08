/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        //step1: insert the copied node
        Node* curr=head;
        while(curr!=NULL){
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        //step2: set random pointers
        curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        //step3: separate both lists
        Node* dummy=new Node(0);
        Node* tail=dummy;

        curr=head;
        while(curr!=NULL){
            Node* copy=curr->next;
            curr->next=copy->next;

            tail->next=copy;
            tail=copy;

            curr=curr->next;
        }
        Node* CopiedHead=dummy->next;
        delete dummy;

        return CopiedHead;
    }
};