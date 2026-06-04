class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> vc;
        for(auto& zz : nums){
            
            vc.push_back(zz);
            sort(vc.begin(), vc.end());
        }
        return vc;
    }
};