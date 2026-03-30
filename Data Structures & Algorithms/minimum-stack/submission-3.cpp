class MinStack {
public:
    stack<int> stk;
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
        vector<int> temp;
        int minum = INT_MAX; 
        while(!stk.empty()){
            int saved = stk.top();
            stk.pop();
            minum = min(minum, saved);
            temp.push_back(saved);
        }
        for(int i = (int)temp.size() -1; i >= 0; i--){
            stk.push(temp[i]);
        }
        return minum;
    }
};
