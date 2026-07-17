class MinStack {
public:
    vector<int> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);    
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int ans = st[0];
        for(int i = 0; i < st.size();i++){
            int a = st[i];
            ans = min(ans,a);
        }
        return ans;
    }
};
