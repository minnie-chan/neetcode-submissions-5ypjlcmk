class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        int newStart = intervals[0][0];
        int newEnd = intervals[0][1];

        while(i < n && intervals[i][1] < newStart){
            res.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newEnd){
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        res.push_back({newStart,newEnd});

        if(i < n){
            vector<vector<int>> sub(intervals.begin() + i, intervals.end());
            vector<vector<int>> remaining = merge(sub);
            res.insert(res.end(), remaining.begin(), remaining.end());
        }
        return res;
    }
};