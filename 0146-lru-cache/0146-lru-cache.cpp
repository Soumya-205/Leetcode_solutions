class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
private:
     int capacity;
     unordered_map<int,Node*>mp;
     Node* head;
     Node* tail;

     void removeNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
     }

     void insertAfterHead(Node* node){
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
     }
public:
    LRUCache(int cap){
        capacity=cap;
        
        //dummy nodes
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    int get(int key){
        //if key doesn't exist in map
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];

        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key,int value){
        //if it exist in map
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
                
            node->value=value;
            removeNode(node);
            insertAfterHead(node);

            return;
        }
        if(mp.size()==capacity){
            Node* lru=tail->prev;
            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
        Node* newNode=new Node(key,value);
        insertAfterHead(newNode);
        mp[key]=newNode;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */