class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int x=nums.size();
        int y=s.size();

        if(x==y){
            return false;
        } 
        else 
        {
            return true;
        }

    }
};
