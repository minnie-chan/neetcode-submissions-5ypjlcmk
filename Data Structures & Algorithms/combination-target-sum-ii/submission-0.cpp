class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> ans;
      vector<int> slave;  
      dfs(candidates,ans,slave,target,0);
      return ans;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& ans,
             vector<int>& slave, int rmg, int start){
        if(rmg == 0){
            ans.push_back(slave);
            return;
        }
        for(int j = start; j < candidates.size(); j++){
            if(candidates[j] > rmg){
                break;
            }
            if (j > start && candidates[j] == candidates[j-1]) continue;
            slave.push_back(candidates[j]);
            
            dfs(candidates, ans, slave, rmg - candidates[j], j+1);
            slave.pop_back();
        }
    }
};
