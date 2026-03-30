class Solution {
public:
   vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string tr;
        if (digits.empty()) return ans;
        dfs(0,digits,ans,tr);
        return ans;
        
    }
    void dfs(int start, string& digits, vector<string>& ans, string& tr){

        if(tr.size() == digits.size()){
            ans.push_back(tr);
            return;
        }
        string word = digitToChar[digits[start] - '0'];
        for(auto cat: word){
            tr.push_back(cat);
            dfs(start + 1, digits, ans, tr);
            tr.pop_back();
        }
    }
};
