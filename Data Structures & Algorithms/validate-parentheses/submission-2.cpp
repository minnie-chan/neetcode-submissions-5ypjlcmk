class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for (auto c : s){
            if (c == '{' || c == '(' || c == '['){
                temp.push(c);
            }
            else {
                if (temp.empty()){
                    return false; 
                }
                char top = temp.top();
                if ((c == '}' && top != '{') || 
                    (c == ']' && top != '[') ||
                    (c == ')' && top != '(')){
                        return false;
                    }
                temp.pop();
            }
        }
        return temp.empty();
    }
};
