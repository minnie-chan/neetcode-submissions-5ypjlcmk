class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> stk;
    for(auto& siz : asteroids){
        if(siz > 0){
            stk.push(siz);
            continue;
        }  else {
            while(!stk.empty() && stk.top() > 0 && stk.top() < -siz){
                stk.pop();
            }
        }
        if(stk.empty() || stk.top() < 0){
            stk.push(siz);
        } else if(stk.top() == -siz){
            stk.pop();
       } else {
            stk.top() > -siz;
       }
    }
  vector<int> res;
    while (!stk.empty()) { 
        res.push_back(stk.top()); 
        stk.pop();
         }
    reverse(res.begin(), res.end());
    return res;

        
        
    }
};