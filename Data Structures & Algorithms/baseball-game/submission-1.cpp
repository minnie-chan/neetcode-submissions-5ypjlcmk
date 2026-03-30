class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int sum = 0;

        for(auto& op : operations) {
           
            if(op == "+") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.push(first);
                stk.push(first+second);
            } else if(op == "D") {
                stk.push(stk.top() * 2);
            } else if(op == "C") {
                    stk.pop();
            } 
             else {
                stk.push(stoi(op));
            }  
            
        }
        while(!stk.empty()){
                
                sum += stk.top();
                stk.pop(); 
            }
        return sum;
    }
};