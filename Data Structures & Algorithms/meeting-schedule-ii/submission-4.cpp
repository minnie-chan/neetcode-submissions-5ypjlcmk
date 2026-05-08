/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& in) {
        if (in.empty()) return 0;
                priority_queue<int, vector<int>, greater<int>> pq;
        sort(in.begin(), in.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });
        pq.push(in[0].end);

        


        for(int i = 1; i < in.size();i++){
            if (in[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(in[i].end);
        }
        return pq.size();
    }
};
