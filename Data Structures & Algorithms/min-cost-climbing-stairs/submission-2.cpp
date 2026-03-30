class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int num1 = cost[0];
        int num2 = cost[1];

        for(int i = 2; i < cost.size(); i++){
            int sum = cost[i] + min(num1, num2);
            num1 = num2;
            num2 = sum;
        }
        return min(num1, num2);
    }
};
