class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> state;
        string result;
        for (string& word : words) {
            for (char c : word) {
                graph[c];
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i + 1];

            int len = min(a.size(), b.size());

            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    graph[a[j]].push_back(b[j]);
                    foundDiff = true;
                    break;
                }
            }

            if (!foundDiff && a.size() > b.size()) {
                return "";
            }
        }
        for (auto& [c, neighbors] : graph) {
            if (state[c] == 0) {
                if (!dfs(c, graph, state, result)) {
                    return "";
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
    bool dfs(char c,unordered_map<char, vector<char>>& graph, unordered_map<char, int>& state, string& result){
        state[c] = 1;

        for (char nei : graph[c]) {
            if (state[nei] == 1) {
                return false;
            }

            if (state[nei] == 0) {
                if (!dfs(nei, graph, state, result)) {
                    return false;
                }
            }
        }

        state[c] = 2;
        result += c;
        return true;
    }
};
