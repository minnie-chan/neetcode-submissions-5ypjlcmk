class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        for(auto token:tokens){

            if(token == "+"){
                int temp = stk.top();
                stk.pop();
                int temps = stk.top();
                stk.pop();
                int sum = temps + temp;
                stk.push(sum);
            } else if(token == "-"){
                int temp = stk.top();
                stk.pop();
                int temps = stk.top();
                stk.pop();
                int sum = temps - temp;
                stk.push(sum);
            } else if(token == "*"){
                int temp = stk.top();
                stk.pop();
                int temps = stk.top();
                stk.pop();
                int sum = temps * temp;
                stk.push(sum);
            } else if(token == "/"){
                int temp = stk.top();
                stk.pop();
                int temps = stk.top();
                stk.pop();
                int sum = temps / temp;
                stk.push(sum);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
        
    }
};
