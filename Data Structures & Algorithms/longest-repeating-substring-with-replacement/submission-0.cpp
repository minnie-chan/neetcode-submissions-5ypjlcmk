class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left = 0 ;
        int right = 0;
        int maxFreq = 0;
        int best = 0;
        while(right < s.size()){
           mp[s[right]]++;
           maxFreq = max(maxFreq, mp[s[right]]);
           while((right - left + 1) - maxFreq > k){
            mp[s[left]] --;
            left ++;
            
           }
           best = max(best, right - left + 1);
            right ++;

        }    
        return best;
    }
};
