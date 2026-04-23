class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }

        int prev = 2;
        int curr = 1;

        for(int i = 3; i <= n; i++){
            int sum = prev + curr;
            curr = prev;
            prev = sum;
        }
        return prev;
    }
};
