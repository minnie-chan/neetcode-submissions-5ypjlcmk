class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int best = 1;
        
        for(int i = 0; i < arr.size(); i++){
            int prev = 0;
            for(int j = i + 1; j < arr.size(); j++){
                int cur = sign(arr[j-1], arr[j]);
                
                if(cur == 0){
                    break;
                }
                if(prev != 0 && cur == prev){
                    break;
                }
                best = max(best, j - i + 1);
                prev = cur;
            }
        }
        return best;
        
    }
    int sign(int a, int b){
        if(a < b){
            return 1;
        }
        if(a > b){
            return -1;
        }
        return 0;
    }
};