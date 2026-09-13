class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int time = 0;

        for (auto& t : tasks) {
            mp[t]++;
        }

        for (auto& a : mp) {
            pq.push(a.second);
        }

        while (!pq.empty() || !q.empty()) {
            time++;

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            if (!pq.empty()) {
                int a = pq.top();
                pq.pop();

                a--;
                if (a > 0) {
                    q.push({a, time + n + 1});
                }
            }
        }
        return time;
    }
};
