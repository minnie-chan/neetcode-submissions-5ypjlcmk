class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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

        while(i < n){
            vector<vector<int>> remaining = merge(vector<vector<int>>(intervals.begin() + i, intervals.end()));
            res.insert(res.end(), remaining.begin(), remaining.end());
            break;
        }
        return res;
    }
};
