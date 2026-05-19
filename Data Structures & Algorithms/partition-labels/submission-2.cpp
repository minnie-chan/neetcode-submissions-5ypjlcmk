class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vc;
        vector<int> word(26);
        for(int i = 0; i < s.size(); i++){
            word[s[i] - 'a'] = i;
        }
        int best = 0;
        int part = 0;

        for(int i = 0; i < s.size();i++){
            best = max(best, word[s[i] - 'a']);

            if(i == best){
                vc.push_back(best - part + 1);
                part = i + 1;
            }
        }
        return vc;
    }
};
