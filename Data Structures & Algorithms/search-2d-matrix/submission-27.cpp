class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int l = 0; 
        int r = m.size() - 1;

        while(l <= r){
            int mi = l + (r - l) / 2;

            if(m[mi][0] == target){
                return true;
            } else if(m[mi][0] < target){
                l = mi + 1;
            } else if(m[mi][0] > target){
                r = mi - 1;
            }
        }

        if(r == -1){
            return false;
        }
        l = 0;
        int a = m[r].size() - 1;

        while(l <= a){
            int middle = l + (a - l) / 2;

            if(m[r][middle] == target){
                return true;
            } else if(m[r][middle] < target){
                l = middle + 1;
            } else if(m[r][middle] > target){
                a = middle - 1;
            }
        }
        return false;
    }
};
