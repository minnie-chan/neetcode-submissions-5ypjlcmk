class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1){
            int sum = 0;
            if(seen.contains(n)){
                return false;
            }
            seen.insert(n);
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};









