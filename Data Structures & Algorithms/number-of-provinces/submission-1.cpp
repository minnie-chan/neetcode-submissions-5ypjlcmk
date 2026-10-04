class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> flag(isConnected.size(), false);
        queue<int> q;
        int b = 0;
        for(int i = 0; i < isConnected.size();i++){

            if(flag[i] == 0){
                flag[i] = true;
                b++;
                q.push(i);

                while(!q.empty()){
                    int a = q.front();
                    q.pop();

                    for(int j = 0; j < isConnected[0].size();j++){

                        if(flag[j] == false && isConnected[a][j] == 1){
                            flag[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return b;
    }
};