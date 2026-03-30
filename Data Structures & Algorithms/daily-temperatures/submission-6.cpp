class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> ans(temperatures.size(), 0);
        stack<int> stk;
        int n = temperatures.size();

        for(int i = 0; i < n; i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int save = stk.top();
                stk.pop();

                ans[save] = i - save;
            }
            stk.push(i);
        }
        return ans;
    }
};
