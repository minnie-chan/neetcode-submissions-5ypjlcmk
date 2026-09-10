class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            if(seen.find(a) != seen.end()){
                return true;
            } else {
                seen.insert(a);
            }
        }
        return false;
    }
};