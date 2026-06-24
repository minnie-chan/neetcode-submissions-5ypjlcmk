class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& n : nums){
            mp[n]++;
        }
        int farthest = 0;
        int l = 0;
        for(auto& [key,value] : mp){
            int a = key;
            if(mp.find(a - 1) == mp.end()){
                l = 1;

                while(mp.find(a + 1) != mp.end()){
                    a++;
                    l++;
                }
                farthest = max(farthest, l);
            }    
        }
        return farthest;
    }
};
