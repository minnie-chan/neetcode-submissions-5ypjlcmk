class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int length = 0;
        int longest = 0;
        for(auto& zz:nums){
            if (st.find(zz -1) != st.end()){
                 continue;

            }
             int current = zz;
            int count = 1;

        while (st.find(current + 1) != st.end()) {
          current++;
          count++;
        }
        longest = max(longest, count);
        }
       

         return longest;
    }
};
