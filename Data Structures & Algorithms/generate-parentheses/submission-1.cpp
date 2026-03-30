class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current = "";
        dfs(n, 0, 0, current, ans);
        return ans;
    }

    void dfs(int n, int open, int close, string& current, vector<string>& ans) {
        
        // Base case: string complete
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Try adding "("
        if (open < n) {
            current.push_back('(');
            dfs(n, open + 1, close, current, ans);
            current.pop_back();
        }

        // Try adding ")"
        if (close < open) {
            current.push_back(')');
            dfs(n, open, close + 1, current, ans);
            current.pop_back();
        }
    }
};