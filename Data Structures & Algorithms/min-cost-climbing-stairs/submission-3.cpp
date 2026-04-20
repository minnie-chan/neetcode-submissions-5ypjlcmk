class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int a = cost[0];
       int b = cost[1];
      
       for(int i = 2; i < cost.size();i++){
            int sum = cost[i] + min(a,b);
            a = b;
            b = sum;
            
       }
        return min(a,b);
    }
};
