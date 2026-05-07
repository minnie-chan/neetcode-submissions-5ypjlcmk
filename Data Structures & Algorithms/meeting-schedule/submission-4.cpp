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
    bool canAttendMeetings(vector<Interval>& in) {
        sort(in.begin(), in.end(), [](auto& a, auto& b) {
            return a.end < b.end;
        });

        int lastEnd = in[0].end;

        for(int i = 1; i < in.size();i++){
            if (in[i].start < lastEnd) {
                return false; // overlap found
            }
            lastEnd = in[i].end;
        }
        return true;
    }
};
