class MinStack {
    private:
    stack <int> stk;
public:
    MinStack() {}  
    
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
       int mn = INT_MAX;
       vector<int> vc;
       while(!stk.empty()){
            int topers = stk.top();
           
             stk.pop();
            
            mn = min(mn , topers);
             vc.push_back(topers);
       }
        for (int i = (int)vc.size() - 1; i >= 0; --i) {
            stk.push(vc[i]);
        }
     
      return mn;
    }
};
