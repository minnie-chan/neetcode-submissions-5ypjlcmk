class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(), 0);

        stack<pair<int,int>> st;

        for(int i = 0; i < temp.size();i++){
             
            while(!st.empty() && temp[i] > st.top().first){
                int a = st.top().second;
                int b = i - a;
                ans[a] = b;
                st.pop();
            }
            st.push({temp[i], i });
        }
        return ans;
    }
};
