class Solution {
public:
    int findCircleNum(vector<vector<int>>& iC) {
        vector<bool> visited(iC.size(), false);
        queue<int> q;
        int ans = 0;
        for(int i = 0; i < iC.size();i++){

            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                ans++;
                while(!q.empty()){

                    int a = q.front();
                    q.pop();
                    for(int j = 0; j < iC.size();j++){
                        
                        if(iC[a][j] == 1 && !visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};