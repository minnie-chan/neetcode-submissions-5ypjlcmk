class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool placed = false;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            auto &cur = intervals[i];

            if (cur[1] < newInterval[0]) {
                res.push_back(cur);
            } 
            else if (cur[0] > newInterval[1]) {
                if(!placed){
                    res.push_back(newInterval);
                    placed = true;
                }    
                res.push_back(cur);
            } 
            else {
                
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max(newInterval[1], cur[1]);               
            }
        }

        if (!placed) {
            res.push_back(newInterval);
        }
        return res;
    }
};
