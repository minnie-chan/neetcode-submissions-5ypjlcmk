class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> starts, ends;
        for (auto& m : intervals) {
            starts.push_back(m.start);
            ends.push_back(m.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;

        while (i < n) {
            if (starts[i] < ends[j]) {
                rooms++;       // need a new room
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;       // free a room
                j++;
            }
        }
        return maxRooms;
    }
};
