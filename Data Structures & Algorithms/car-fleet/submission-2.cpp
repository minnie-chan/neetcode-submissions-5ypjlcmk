class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int fleets = 1;
        for (int i = 0; i < position.size(); i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end());
        int n = vec.size() ;
        double lastFleetTime = (double)(target - vec[n - 1].first) / vec[n - 1].second;
        for(int i = vec.size() - 1;i >= 0;i--){
            double time = (double)(target - vec[i].first) / vec[i].second;

            if (time > lastFleetTime){
                fleets++;
                lastFleetTime = time;
            }
        }
        return fleets;
    }
};
