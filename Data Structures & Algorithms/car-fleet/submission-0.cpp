class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int, double>> cars;

 for (int i = 0; i < position.size(); ++i) {
    double time = (target - position[i]) / (double)speed[i];
    cars.push_back({position[i], time});
 }

       sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
    return a.first > b.first; 
    });

        int fleets = 0;
        double slowest_time = 0.0;

        for(auto& car : cars){
            double time = car.second;
            if(time > slowest_time){
                fleets += 1;
                slowest_time = time;
            }
        }
        return fleets;
    }
};
