class MinStack {
public:
    stack<int>minst,normalst;
    MinStack() {
        
    }
    
    void push(int val) {
        normalst.push(val);
        if(minst.empty() || val<=getMin())minst.push(val);
    }
    
    void pop() {
        if(normalst.top()==getMin())minst.pop();
        normalst.pop();
    }
    
    int top() {
        return normalst.top();
    }
    
    int getMin() {
        return minst.top();
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