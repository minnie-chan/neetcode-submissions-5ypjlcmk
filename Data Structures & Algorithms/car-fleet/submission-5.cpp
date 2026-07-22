class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();  
        vector<pair<int,int>> vec;
        int fleets = 1;

        for(int i = 0; i < n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(), vec.end());
        int nn = vec.size();
        double time = (double)(target - vec[nn - 1].first) / vec[nn - 1].second;

        for(int i = n - 2; i >= 0; i--){
            double nt = (double)(target - vec[i].first) / vec[i].second;
            if(nt > time){
                fleets++;
                time = nt;
            }
        }
        return fleets;
    }
};
