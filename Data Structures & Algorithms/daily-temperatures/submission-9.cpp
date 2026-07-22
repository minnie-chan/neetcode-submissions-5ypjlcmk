class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> vec(n,0);
        for(int i = 0; i < n;i++){
            
            while(!st.empty() && temperatures[i] > st.top().first){
                int prevIndex = st.top().second;
                st.pop();
                vec[prevIndex] = i - prevIndex;
            }
            st.push({temperatures[i], i});
        }
        return vec;
    }
};
