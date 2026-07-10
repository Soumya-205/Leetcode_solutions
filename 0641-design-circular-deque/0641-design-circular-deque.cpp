class MyCircularDeque {
public:
    vector<int>dq;
    int frontIndex=0;
    int rearIndex=-1;
    int size=0;
    int capacity;
    MyCircularDeque(int k) {
        capacity=k;
        dq.resize(k);
    }
    
    bool insertFront(int value) {
        if(size==capacity){
            return false;
        }
        if(size==0){
            frontIndex=rearIndex=0;
        }else{
            frontIndex=(frontIndex-1+capacity)%capacity;
        }
        dq[frontIndex]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity){
            return false;
        }
        if(size==0){
            frontIndex=rearIndex=0;
        }else{
            rearIndex=(rearIndex+1)%capacity;
        }
        dq[rearIndex]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0){
            return false;
        }
        if(size==1){
            frontIndex=0;
            rearIndex=0;
        }else{
            frontIndex=(frontIndex+1)%capacity;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0){
            return false;
        }
        if(size==1){
            frontIndex=0;
            rearIndex=-1;
        }else{
            rearIndex=(rearIndex-1+capacity)%capacity;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0){
            return -1;
        }
        return dq[frontIndex];
    }
    
    int getRear() {
        if(size==0){
            return -1;
        }
        return dq[rearIndex];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */