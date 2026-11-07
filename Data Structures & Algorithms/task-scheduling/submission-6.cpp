class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char t : tasks) {
            mp[t]++;
        }

        priority_queue<int> pq;

        for (auto& [task, count] : mp) {
            pq.push(count);
        }

        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // cooldown finishes BEFORE we pick a task this second
            if (!cooldown.empty() &&
                cooldown.front().second <= time) {

                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int curr = pq.top();
                pq.pop();

                curr--;

                if (curr > 0) {
                    cooldown.push({curr, time + n + 1});
                }
            }
        }

        return time;
    }
};