class MyCircularQueue {
public:
    vector<int>q;
    int rearIndex=-1;
    int frontIndex=0;
    int size=0;
    int capacity;
    MyCircularQueue(int k) {
        capacity=k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(size==capacity){
            return false;
        }

        rearIndex=(rearIndex+1)%capacity;
        q[rearIndex]=value;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size==0){
            return false;
        }
        frontIndex=(frontIndex+1)%capacity;
        size--;

        return true;
    }
    
    int Front() {
        if(size==0){
            return -1;
        }
        return q[frontIndex];
    }
    
    int Rear() {
        if(size==0){
            return -1;
        }
        return q[rearIndex];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */