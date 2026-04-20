class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int track = 0;
        int move = 0;
        while(move <= cost.size()){
            move += 2;
            track++;
        }
        return track;
    }
};
