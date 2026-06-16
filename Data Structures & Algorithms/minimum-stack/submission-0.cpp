class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        data.pop();
        minStack.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    stack<int> data;
    stack<int> minStack;
};
