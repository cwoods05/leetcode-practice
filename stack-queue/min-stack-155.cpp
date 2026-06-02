class MinStack {
private:
    stack<int> values;
    stack<int> mins;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if(mins.empty() || val < mins.top()){
            mins.push(val);
        }
        else{
            mins.push(mins.top());
        }
        
    }
    
    void pop() {
        if(!values.empty()){
            if(!mins.empty()){
                mins.pop();
            }
            values.pop();
        }
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
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