class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_map<int,int> mp;

        for(auto& a : nums){
            mp[a]++;
        }

        int longest = 1;
        int curr = 0;
        for(auto& [key,value] : mp){
            int a = key - 1;
            if(mp.find(a) == mp.end()){
                a = key;
                curr = 1;

                while(mp.find(a + 1) != mp.end()){
                    a++;
                    curr++;
                }
                longest = max(longest, curr);
            }

        }
        return longest;
    }
};
