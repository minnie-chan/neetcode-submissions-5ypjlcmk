class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> a(t.size(), 0);
        stack<pair<int,int>> st;
        for(int i = 0; i < t.size();i++){

            while(!st.empty() && t[i] > st.top().first){

                int prevIndex = st.top().second;
                st.pop();
                a[prevIndex] = i - prevIndex;
            }
            st.push({t[i], i});
        }
        return a;
    }
};
