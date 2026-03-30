class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto& zz: nums){
            mp[zz] += 1;
        }

        vector<vector <int> > vc(nums.size() + 1);
        for(auto& [key,value] : mp){
            vc[value].push_back(key);
        }
        vector<int> result;
        for(int i = nums.size(); i >= 1; i--){
            for(auto& aa : vc[i]){
                result.push_back(aa);
                if(result.size() == k) {
                    break;
                }
            }
            if(result.size() == k){
                break;
            }
        }
            return result;
    }
};
