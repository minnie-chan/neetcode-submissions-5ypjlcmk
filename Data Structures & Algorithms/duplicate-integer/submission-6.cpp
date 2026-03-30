class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int x:nums){
            m[x]++;
        }
        
        for(auto x:m){
            if(x.second>1)return true;
        }
        return false;
    }
};
