class Solution {
public:
    bool isValid(string s) {
       stack<char> st;

       for(auto& a : s){
            if(a == '(' || a == '{' || a == '['){
                st.push(a);
            } else {
                if(st.empty()){
                    return false;
                } else if(a == ')' && st.top() == '('){
                        st.pop();
                }else if(a == '}' && st.top() == '{'){
                    st.pop();
                }else if(a == ']' && st.top() == '['){
                    st.pop();
                } else{
                    return false;
                }
            }
       } 
       return st.empty();
    }
};
