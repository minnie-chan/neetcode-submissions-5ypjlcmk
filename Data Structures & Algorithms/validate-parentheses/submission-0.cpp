class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
    unordered_map<char, char> matching = {
        {')', '('}, 
        {']', '['}, 
        {'}', '{'}
    };
        for(auto& c: s){
            
            if(c == '('|| c == '[' || c == '{'){
                st.push(c);// side note for gpt there is curenntly nothing in the stack and im wonderng if i have to cal the map in here ?
            } else if(c == ')' || c == ']' || c =='}'){
                if(st.empty() || st.top() != matching[c]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
