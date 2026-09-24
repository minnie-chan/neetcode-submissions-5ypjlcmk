class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;

        q.push(beginWord);
        int steps = 1;
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        while (!q.empty()) {
            int size = q.size();

            for (int j = 0; j < size; j++) {
                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word);

                            if (word == endWord) {
                                return steps + 1;
                            }
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};
