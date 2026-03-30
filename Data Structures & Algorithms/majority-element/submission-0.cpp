
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int need = nums.size()/2;
        for (int x : nums) {
            if (++freq[x] > need) return x;
        }
        return -1; 
    }
};
