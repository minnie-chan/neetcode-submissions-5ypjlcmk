class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
         int prevEnd = intervals[0][1];
        int track = 0;
        
        for(int i = 1; i <= n - 1; i++){
           
            if(intervals[i][0] < prevEnd){ 
                track++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return track;
    }
};
