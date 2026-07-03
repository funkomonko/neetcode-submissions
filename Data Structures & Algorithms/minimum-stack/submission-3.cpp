class MinStack {
    stack<int>minStack, minVals;
    int minVal = pow(2, 31)-1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(val);
        if(minVal>=val){
            minVal = val;
            minVals.push(val);
        }
    }
    
    void pop() {
        if(minVal == minStack.top()){
            minVals.pop();
            if(!minVals.empty()){
                minVal = minVals.top();
            }
        }
        minStack.pop();
        if(minStack.empty()){
            minVal = pow(2,31)-1;
        }
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minVal;
    }
};
