class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        st.push(0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int width ;

                if(st.empty()){
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                ans = max(ans, width * height);
            }
            st.push(i);
        }
        return ans;
    }
};
