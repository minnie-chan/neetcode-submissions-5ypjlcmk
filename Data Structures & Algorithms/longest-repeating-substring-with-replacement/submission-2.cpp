class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left = 0;
        int best = 0;
        int max_size = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            max_size = max(max_size, mp[s[right]]);
            while((right - left + 1) - max_size > k){
                mp[s[left]]--;
                left++;
            }

            best = max(best, right - left + 1);
        }
        return best;
    }
};
