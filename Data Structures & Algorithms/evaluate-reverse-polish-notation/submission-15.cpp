class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& a : tokens){
            if(a == "+"){
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();
                st.push(b + c);
            } else if(a == "-"){
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();
                st.push(c - b);
            } else if(a == "*"){
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();
                st.push(b * c);
            } else if(a == "/"){
                int b = st.top();
                st.pop();
                int c = st.top();
                st.pop();
                st.push(c / b);
            } else {
                int z = stoi(a);
                st.push(z);
            }
        }
        return st.top();
    }
};
