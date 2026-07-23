class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int ans = 0;
        st.push(0);
        for(int i = 1; i < heights.size();i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int a = heights[st.top()];
                st.pop();

                int c;

                if(st.empty()){
                    c = i;
                } else {
                    c = i - st.top() - 1;
                }
                ans = max(ans, c * a);
            }
            st.push(i);
        }
        return ans;
    }
};
