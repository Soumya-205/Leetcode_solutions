/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* head){
        Node* curr=head;
        Node* last=head;

        while(curr!=NULL){
            Node* nextNode=curr->next;

            if(curr->child!=NULL){
                Node* childHead=curr->child;
                Node* childTail=dfs(childHead);

                curr->next=childHead;
                childHead->prev=curr;

                curr->child=NULL;

                if(nextNode!=NULL){
                    childTail->next=nextNode;
                    nextNode->prev=childTail;
                }
                last=childTail;
            }else{
                last=curr;
                curr=nextNode;
            }
        }
        return last;
    }
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        dfs(head);
        return head;
    }
};