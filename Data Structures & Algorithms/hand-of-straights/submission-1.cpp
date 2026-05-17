class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        for (auto& a : hand) {
            mp[a]++;
        }
        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++) {
            int card = hand[i];
            if (mp[card] == 0) {
                continue;
            }
            for (int a = card; a < card + groupSize;a++) {
                if (mp[a] == 0) {
                    return false;
                }
                mp[a]--;
            }
        }
        return true;
    }
};
