class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int length = 1;

        for(int i = 0; i < arr.size(); i++){
            int prev = 0;
            for(int j = i + 1; j < arr.size(); j++){
                int current = check(arr[j - 1], arr[j]);

                if(current != 0 && current == prev){
                    break;
                }
                if(current == 0){
                    break;
                }
                
                length = max(length, j - i + 1);
                prev = current;
            }
        }
        if(arr.size() == 1){
            return length;
        }
        return length;
    }
    int check(int a, int b){
        if(a < b){
            return 1;
        } else if(a > b){
                return -1;
        }
        return 0;
    }
};