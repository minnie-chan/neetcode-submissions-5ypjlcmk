class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int maxArea = 0;
        int width;
            for(int i  = 0; i < heights.size() ; i++){  // im a bit confused on where to put the -1 
                while(!st.empty() && heights[i] < heights[st.top()]){
                        int topindex  = st.top();
                        int height = heights[topindex];
                            st.pop();
                            if(st.empty()){
                                 width = i;
                                
                            } else {
                               width = i - st.top() -1;
                            }
                           int area = height * width;
                           if(area > maxArea){
                            maxArea = area;
                           }
                }
                
                           
                st.push(i);
            }
            return maxArea;
    }
};
