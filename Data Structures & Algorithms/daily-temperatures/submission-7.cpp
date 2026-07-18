class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);

        stack<pair<int,int>> st;

        for (int i = 0; i < temperatures.size(); i++) {
            
            while (!st.empty() && temperatures[i] > st.top().first){
                int oldIndex = st.top().second;
                ans[oldIndex] = i - oldIndex;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};