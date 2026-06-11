class Node{
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url){
        this->url=url;
        prev=NULL;
        next=NULL;
    }
};
class BrowserHistory {
private:
    Node* current;
public:
    BrowserHistory(string homepage) {
       current=new Node(homepage); 
    }
    
    void visit(string url) {
        //delete all forward history
        Node* temp=current->next;
        while(temp){
            Node* nxt=temp->next;
            delete temp;
            temp=nxt;
        }
        current->next=NULL;
        //create new Node
        Node* newNode=new Node(url);

        current->next=newNode;
        newNode->prev=current;

        current=newNode;
    }
    
    string back(int steps) {
        while(steps>0 && current->prev!=NULL){
            current=current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps>0 && current->next!=NULL){
            current=current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */