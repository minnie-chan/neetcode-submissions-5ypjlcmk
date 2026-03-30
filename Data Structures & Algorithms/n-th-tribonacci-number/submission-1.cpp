class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        int num1 = 0;
        int num2 = 1;
        int num3 = 1;

        for(int i = 3; i <= n; i++){
            int sum = num1 + num2 + num3;
            num1 = num2;
            num2 = num3;
            num3 = sum;
        }
        return num3;
    }
};