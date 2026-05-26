class Solution {
public:

    // DFS function for topological sort
    bool dfs(char c,
             unordered_map<char, vector<char>>& graph,
             unordered_map<char, int>& state,
             string& result)
    {
        // mark current char as "visiting"
        state[c] = 1;

        // visit all neighbors
        for (char nei : graph[c]) {

            // cycle found
            if (state[nei] == 1) {
                return false;
            }

            // if unvisited, DFS again
            if (state[nei] == 0) {
                if (!dfs(nei, graph, state, result)) {
                    return false;
                }
            }
        }

        // mark as fully done
        state[c] = 2;

        // add to result AFTER neighbors
        result += c;

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        // graph: char -> neighbors
        unordered_map<char, vector<char>> graph;

        // state:
        // 0 = unvisited
        // 1 = visiting
        // 2 = done
        unordered_map<char, int> state;

        string result;

        // add every character to graph
        for (string& word : words) {
            for (char c : word) {
                graph[c];
            }
        }

        // build graph edges
        for (int i = 0; i < words.size() - 1; i++) {

            string a = words[i];
            string b = words[i + 1];

            int len = min(a.size(), b.size());

            bool foundDiff = false;

            // compare characters
            for (int j = 0; j < len; j++) {

                // first different character matters
                if (a[j] != b[j]) {

                    // a[j] comes before b[j]
                    graph[a[j]].push_back(b[j]);

                    foundDiff = true;

                    break;
                }
            }

            // invalid case:
            // "abc" before "ab"
            if (!foundDiff && a.size() > b.size()) {
                return "";
            }
        }

        // run DFS on every character
        for (auto& [c, neighbors] : graph) {

            // only start DFS if unvisited
            if (state[c] == 0) {

                // cycle detected
                if (!dfs(c, graph, state, result)) {
                    return "";
                }
            }
        }

        // DFS builds answer backwards
        reverse(result.begin(), result.end());

        return result;
    }
};