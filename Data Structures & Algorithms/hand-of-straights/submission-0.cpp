class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> count;
        

        for (int a : hand) {
            count[a]++;
        }

        sort(hand.begin(), hand.end());

        for (auto& a : hand) {
            if (count[a] == 0) {
                continue;
            }
            for (int next = a; next < a + groupSize; next++) {
                if (count[next] == 0) {
                    return false;
                }
                count[next]--;
            }
        }
        return true;
    }
};
