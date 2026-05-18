class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> vc = {false,false,false};

        for(auto& trip: triplets){
            if(trip[0] > target[0] ||
               trip[1] > target[1] ||
               trip[2] > target[2]){
                continue;
            }

            for(int i = 0; i < 3; i++){
                if(trip[i] == target[i]){
                    vc[i] = true;
                }
            }
        }
        return vc[0] && vc[1] && vc[2];
    }
};
