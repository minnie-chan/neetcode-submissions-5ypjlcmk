class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> num;
        
        
         for ( int i = 0; i < tokens.size(); i++){
             if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    int result;
                    if(tokens[i] == "+"){
                        result = num1 + num2;} 

                    else if (tokens[i] == "-"){
                        result = num2 - num1;}
                       
                        else if (tokens[i] == "*"){
                        result = num1 * num2;
                      }

                     else if (tokens[i] == "/"){
                        result = num2 / num1;
                     }

                  

                       
                    num.push(result);
               } else {   int val = std::stoi(tokens[i]);
                            num.push(val);   }
            
         }
         return num.top();
    }
};
