class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> track;
        dfs(0,candidates, ans, track, target);
        return ans;
    }
    void dfs(int climber, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& track, int t){
        
        if(t == 0){
            ans.push_back(track);
            return;
        }

        for(int i = climber; i < candidates.size(); i++){
            if(candidates[i] > t ){
                break;
            }
            if(i > climber && candidates[i - 1] == candidates[i]){
                continue;
            }
            track.push_back(candidates[i]);
            dfs(i + 1,candidates, ans, track, t - candidates[i]);

            track.pop_back();
        }
    }
};
