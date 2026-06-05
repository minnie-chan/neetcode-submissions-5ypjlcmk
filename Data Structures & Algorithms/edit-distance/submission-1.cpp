class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dfs(0,0,word1,word2,memo);
    }
    int dfs(int i, int j, string& word1, string& word2, vector<vector<int>>& memo){
        if(i == word1.size()){
            return word2.size() -j;
        }
        if(j == word2.size()){
            return word1.size() -i;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(word1[i] == word2[j]){
            return dfs(i+1,j+1,word1,word2,memo);
        }
        int a = 1 + dfs(i,j+1,word1,word2,memo);
        int b = 1+ dfs(i+1,j,word1,word2,memo);
        int c = 1+ dfs(i+1,j+1,word1,word2,memo);

        return memo[i][j] =  min({a,b,c});
    }
};
