class MyStack {
    private: 
    queue <int> qu;
public:
    MyStack() {} 
    
    void push(int x) {
        qu.push(x);
    }
    
    int pop() {
        int n = qu.size();
        for(int i = 0; i < n-1; i++){
                 int frt = qu.front();
                 qu.pop();
                 qu.push(frt);
               
        }  
        int ans = qu.front();
        qu.pop();
        return ans;
    }
    
    int top() {
        return qu.back();
    }
    
    bool empty() {
        if(qu.empty()){
            return true;
        } else {
             return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */