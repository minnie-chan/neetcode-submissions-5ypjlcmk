class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto& zz : s){
            char need;
            switch (zz) {
                case ')': need = '('; break;
                case '}': need = '{'; break;
                case ']': need = '['; break;
            }
            if(zz == '(' || zz == '{' || zz == '['){
                st.push(zz);
                continue;
            } else {
                
            
            if(st.empty()){
                return false;
            }
             if(st.top() == need) {
                st.pop(); 
                
            } else { return false;  }
            }
           

        }
        return st.empty();
    }
};
