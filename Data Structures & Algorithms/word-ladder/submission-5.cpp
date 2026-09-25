class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set st(wordList.begin(), wordList.end());

        queue<string> q;

        q.push(beginWord);
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int j = 0; j < size; j++) {
                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word);
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
