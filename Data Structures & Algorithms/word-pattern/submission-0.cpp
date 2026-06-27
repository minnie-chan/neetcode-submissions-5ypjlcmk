class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pToWord;
        unordered_map<string, char> wordToP;

        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            string word = words[i];

            if(pToWord.find(p) != pToWord.end() && pToWord[p] != word){
                return false;
            }
            if(wordToP.find(word) != wordToP.end() && wordToP[word] != p){
                return false;
            }
            pToWord[p] = word;
            wordToP[word] = p;
        }
        return true;
    }
};