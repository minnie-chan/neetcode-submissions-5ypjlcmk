class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> stk;
        
        for(auto& siz : tokens){
            if(siz == "+"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b + a);
            } else if(siz == "-"){
                    int c = stk.top();
                    stk.pop();
                    int d = stk.top();
                    stk.pop();
                    stk.push(d - c);
            } else if(siz == "*"){
                    int e = stk.top();
                    stk.pop();
                    int f = stk.top();
                    stk.pop();
                    stk.push(f * e);
            } else if(siz == "/"){
                    int g = stk.top();
                    stk.pop();
                    int k = stk.top();
                    stk.pop();
                    stk.push(k / g);
            } else {
                stk.push(stoi(siz));
            }
        }
        return stk.top();
    }
};
