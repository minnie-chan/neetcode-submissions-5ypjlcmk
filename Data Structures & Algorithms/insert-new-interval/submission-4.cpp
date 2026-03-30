class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = newInterval[0];
        int r = newInterval[1];
        vector<vector<int>> vc;
        int i = 0;
        while(i < n && intervals[i][1] < l){
            vc.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= r){
            l = min(l, intervals[i][0]);
            r = max(r, intervals[i][1]);
            i++;
        }
        vc.push_back({l,r});
        while(i < n){
            vc.push_back(intervals[i]);
            i++;
        }
        return vc;
    }
};
