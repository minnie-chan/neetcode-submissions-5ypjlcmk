class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto& a : nums){
            mp[a]++;
        }
        vector<int> vc(k, 1);

        int a = 0;
        int b = 0;
        for(int i = 0; i < k;i++){
            a = 0;
            for(auto [key,value]: mp){
                
                if(value > a){
                    a = value;
                    b = key;
                    
                }
                
            }
            vc[i] *= b;
            mp.erase(b);
        }

        return vc;
    }
};
