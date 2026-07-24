class Solution {
public:
    bool isValid(string s) {
        stack<int> stq;

        for(auto& a : s){
            if(a == '(' || a == '{' || a == '['){
                stq.push(a);
            } else {
                if(stq.empty()){
                    return false;
                } else if(stq.top() == '(' && a == ')'){
                    stq.pop();
                } else if(stq.top() == '[' && a == ']'){
                    stq.pop();
                } else if(stq.top() == '{' && a == '}'){
                    stq.pop();
                } else {
                    return false;
                }
            }
        }
        return stq.empty();
    }
};
