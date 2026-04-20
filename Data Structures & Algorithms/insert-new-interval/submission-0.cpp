class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        int newStart = newInterval[0];
        int newEnd   = newInterval[1];
        while(i < n && inttervals[i][1] < newstart){
            res.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newEnd){
            newstart = min(newstart, intervals[i][0]);
            newEnd = max(newstart, intervals[i][1]);
            i++;
        }
        res.push_back({newstart, newEnd});
        while (i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
