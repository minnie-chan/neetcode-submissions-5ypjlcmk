class MinStack {
   public:
    MinStack() {}
    stack<int> st;
    stack<int> mins;
    void push(int val) {
        st.push(val);

        if (mins.empty()) {
            mins.push(val);
        } else {
            mins.push(min(val, mins.top()));
        }
    }

    void pop() {

        st.pop();
        mins.pop();
    
    }

    int top() {

        return st.top();
    
    }

    int getMin() {
        int getMin() ;
        return mins.top();
    
    }
};
