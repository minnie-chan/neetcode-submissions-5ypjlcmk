class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int ans = 0;

        for(auto& n : nums){
            mp.insert(n);
        }

        for (auto& key : mp) {
    if (mp.find(key - 1) == mp.end()) {
        int q = 1;
        int a = key + 1;

        while (mp.find(a) != mp.end()) {
            q++;
            a++;
        }

        ans = max(ans, q);
    }
}
        return ans;
    }
};
