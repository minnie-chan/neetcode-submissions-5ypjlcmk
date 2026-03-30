class Solution {
public:
int numDecodings(string s) {
    int n = s.size();
    if (s[0] == '0') return 0;

    int prev2 = 1; 
    int prev1 = 1; 

    for (int i = 2; i <= n; i++) {
        int cur = 0;
        if(s[i-1] != '0'){
            cur += prev1;
            
        } 
        if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7'){
            cur += prev2;
        }
       

        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}
};