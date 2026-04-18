class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        int count = 1;

        while(!q.empty()){
            auto [currWord, steps] = q.front();
            q.pop();

            for (const string& word : wordList) {
                if(!visited.count(word) && oneLetterDifferent(currWord, word)){
                    if(word == endWord){
                        return steps + 1;
                    }
                    visited.insert(word);
                    q.push({word, steps + 1});
                }
            }
        }
        return 0;
    }
    bool oneLetterDifferent(const string& a, const string& b){
        int aa = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                aa++;
            }
            
        }
        if(aa == 1){
            return true;
        } else{
            return false;
        }
    }
};
