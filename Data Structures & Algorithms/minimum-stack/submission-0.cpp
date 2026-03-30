class MinStack {
    private:
    stack<int> sk;
    stack<int> minsk;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        sk.push(val);

        if(minsk.empty() || val <= minsk.top()){
            minsk.push(val);
        } else {
            minsk.push(minsk.top());
        }
    }
    
    void pop() {
        
        sk.pop();
        minsk.pop();
    }
    
    int top() {
        return  sk.top();
    }
    
    int getMin() {
        return minsk.top();
    }
};
