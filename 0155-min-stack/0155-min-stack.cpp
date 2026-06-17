class MinStack {
private:
    stack<int>st;
    stack<int>minSt;
public:
    //push element
    void push(int val){
        st.push(val);

        if(!minSt.empty()){
            minSt.push(min(val,minSt.top()));
        }else{
            minSt.push(val);
        }
    }
    //remove the element
    void pop(){
        if(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    //return the top of the stack
    int top(){
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    //return minimum element
    int getMin(){
        if(!minSt.empty()){
            return minSt.top();
        }
        return -1;
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */