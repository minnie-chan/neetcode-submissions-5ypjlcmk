class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            for(int meow = i + 1; meow < nums.size(); meow++){
                 if (nums [i] == nums [meow]){
                    return true;
                }
            }
        }
        return false;
    }
};
