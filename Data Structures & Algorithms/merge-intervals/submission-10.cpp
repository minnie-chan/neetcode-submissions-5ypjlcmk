class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        int res_i = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= res[res_i][1])
            {
                res[res_i][0] = min(res[res_i][0], intervals[i][0]);
                res[res_i][1] = max(res[res_i][1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
                res_i++;
            }
        }
        return res;
    }
};
