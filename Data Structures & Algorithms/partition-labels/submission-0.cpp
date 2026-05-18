class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans; 
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        int best = 0;
        int start = 0;
        for(int i = 0;i < s.size(); i++){
            best = max(best, last[s[i] -'a']);

            if(i == best){
                ans.push_back(best - start + 1);
                start = i + 1;
            }
        }
        return ans ;
    }
};
