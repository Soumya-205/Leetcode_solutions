class MyQueue {
private: 
    stack<int>input;
    stack<int>output;
public:
    //push the element into input
    void push(int x){
        input.push(x);
    }
    //remove and return the element
    int pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int ans=output.top();
        output.pop();
        return ans;
    }
    //return the top element
    int peek(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    //check if queue is empty
    bool empty(){
        return input.empty() && output.empty();
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */