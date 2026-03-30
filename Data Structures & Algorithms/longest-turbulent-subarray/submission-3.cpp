class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int best = 1;
        int length = 1;
        int prev = 0;
        for(int j = 1; j < arr.size(); j++){
           
            int current = sign(arr[j-1], arr[j]); 
            
            if(current == 0){
                length = 1;
                prev = 0;
            } else if(prev == 0){
                length = 2;
                prev = current;
            } else if(current == prev){
                length = 2;
                prev = current;
            } else {
                length++;
                prev = current;
            }

            best = max(best, length);
        }
        return best;
    }
    int sign(int a, int b){
        if(a < b){
            return 1;
        } else if(a > b){
                return -1;
        }
        return 0;
    }
};