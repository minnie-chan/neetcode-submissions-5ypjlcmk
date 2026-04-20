class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
                unordered_map <int,int> mp;

                        for(auto& size:nums){
                                    mp[size]++;
                                            }
                                                    
                                                            for(auto& [key,value]:mp){
                                                                        if(value > 1){
                                                                                        return true;
                                                                                                    } 
                                                                                                                
                                                                                                                        }
                                                                                                                                return false;
                                                                                                                                    }
                                                                                                                                    };
}