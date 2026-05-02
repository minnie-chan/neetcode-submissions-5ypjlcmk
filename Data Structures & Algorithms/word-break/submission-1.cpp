class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return solve(0, s, dict, memo);
    }

    bool solve(int start, string& s, unordered_set<string>& dict, vector<int>& memo) {
       if(start == s.size()){
            return true;
       }
       if(memo[start] != -1){
            return memo[start];
       }

       for (int end = start; end < s.size(); end++) {
            string sub = s.substr(start, end - start + 1);
            
            if (dict.count(sub)) {
                if(solve(end + 1, s, dict, memo)){
                    memo[start] = 1;
                    return true;
                }
            }
        }
        memo[start] = 0;
        return false;
    }
};