class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        if(nums.size() == 0){
            return 0;
        }
        for(auto& n : nums){
            mp[n]++;
        }

        int longest = 1;
        int curr = 0;
        for(auto& [key,value] : mp){
            int a = key - 1;
            if(mp.find(a) == mp.end()){
                curr = 1;
                a = key;
                
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
