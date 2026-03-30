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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1){
            return true;
        }
        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        int ends = intervals[0].end;
        
        for(int i = 1; i < n; i++){
            if(intervals[i].start < ends){
                return false;
            } 
            ends = intervals[i].end;
        }
        return true;
    }
};
