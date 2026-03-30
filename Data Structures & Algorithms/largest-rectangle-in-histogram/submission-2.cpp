class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i = 0 ; i < heights.size(); i++){
            int j = i + 1;
            int width = 1; 
            
            while(j < heights.size() && heights[j] >= heights[i]  ){
                width ++;
                j++;
            }
            for(int k = i - 1; k >= 0; k--){
                    if( heights[k] >= heights[i]){
                        width ++;
                    }
                    else { break;}

            }
            int area;
            area = heights[i] * width;
            if(area > maxArea) {
                maxArea = area ;
            }
        }
        return maxArea;
    }
};
