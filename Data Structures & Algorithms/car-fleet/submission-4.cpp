class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int fleets = 1;

        for(int i = 0; i < speed.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(), vec.end());
        int n = vec.size();

        double time = (double)(target - vec[n - 1].first) / vec[n - 1].second;
        
        for(int i = n - 2 ; i >= 0;i--){
            
            double nft = (double)(target - vec[i].first) / vec[i].second;
            
            if(nft > time){
                fleets++;
                time = nft;
            }
        }
        return fleets;
    }
};