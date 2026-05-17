class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> vec = {false,false,false};

        for(auto& trip: triplets){
            if(trip[0] > target[0] ||
               trip[1] > target[1] ||
               trip[2] > target[2]){
                continue;
            }


            for(int i = 0; i < 3; i++){
                if(trip[i] == target[i]){
                    vec[i] = true;
                }
            }
        }
        return vec[0] && vec[1] && vec[2];
    }
};
