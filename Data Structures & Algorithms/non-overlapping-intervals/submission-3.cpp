class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.size() == 0){
            return 0;
        }
        int n = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int track = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] == res.back()[1]){
                res.push_back(intervals[i]);
                continue;
                } else if(intervals[i][0] < res.back()[1]){        
                track++;
                intervals.pop_back();
            } else if(intervals[i][0] > res.back()[1]){
                res.push_back(intervals[i]);
            }
        }
        return track;
    }
};
