class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        return func(n,st);
    }
    bool func(int& n,unordered_set<int> st){
        if(n == 1){
            return true;
        }
        if(st.find(n) != st.end()){
            return false;
        }
        st.insert(n);
        int sum = 0 ;

        while(n > 0){
            int a = n % 10;
            sum += a * a;
            n = n / 10;
        }

        return func(sum,st);
    }
};
