class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> slave;
        dfs(n,k,ans,slave,1);
        return ans;
    }
    void dfs(int n, int k,vector<vector<int>>& ans,
              vector<int>& slave, int start){
        if(slave.size() == k){
            ans.push_back(slave);
            return;
        }
        if(slave.size() > k){ 
            return;
        }
        
        for(int i = start; i <= n; i++){
            int need = k - slave.size();
            int left = n - i + 1;
            if(need > left){
                break;
            }
            slave.push_back(i);
            dfs(n,k,ans,slave, i + 1);
            slave.pop_back();
        }
    };
};
