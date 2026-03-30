class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> stk;
        int prev = 0;
        int n = t.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){

            while(!stk.empty() && t[i] > t[stk.top()]){
                prev = stk.top();
                stk.pop();

                ans[prev] = i - prev;
            }
            stk.push(i);
        }
        return ans;
    }
};
